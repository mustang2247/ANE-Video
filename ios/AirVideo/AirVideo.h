//////////////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2012 Freshplanet (http://freshplanet.com | opensource@freshplanet.com)
//  
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//  
//    http://www.apache.org/licenses/LICENSE-2.0
//  
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//  
//////////////////////////////////////////////////////////////////////////////////////

#import "FlashRuntimeExtensions.h"
#import <MediaPlayer/MediaPlayer.h>
#import "FPANEUtils.h"

@interface AirVideo : NSObject
{
    NSInteger currentVideoPosition;
    NSMutableDictionary* videosData;
    CGRect  requestedFrame;
}
@property (nonatomic, readonly) MPMoviePlayerController *player;
@property (nonatomic, retain) NSMutableDictionary* videosData;
@property (nonatomic) NSInteger currentVideoPosition;
@property (nonatomic, assign) CGRect requestedFrame;


+ (id)sharedInstance;
+ (void)dispatchEvent:(NSString *)eventName withInfo:(NSString *)info;
+ (void)log:(NSString *)message;

-(void)storeVideoData:(NSData*)data atPosition:(NSInteger)position;

@end


// C interface
DEFINE_ANE_FUNCTION(showPlayer);
DEFINE_ANE_FUNCTION(hidePlayer);
DEFINE_ANE_FUNCTION(fetchVideo);
DEFINE_ANE_FUNCTION(setViewDimensions);
DEFINE_ANE_FUNCTION(setControlStyle);
DEFINE_ANE_FUNCTION(playVideo);
DEFINE_ANE_FUNCTION(bufferVideos);
DEFINE_ANE_FUNCTION(pauseCurrentVideo);
DEFINE_ANE_FUNCTION(resumeVideo);
DEFINE_ANE_FUNCTION(cleanUp);
DEFINE_ANE_FUNCTION(prepareToPlay);

// ANE Setup
void AirVideoContextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctionsToTest, const FRENamedFunction** functionsToSet);
void AirVideoContextFinalizer(FREContext ctx);
void AirVideoInitializer(void** extDataToSet, FREContextInitializer* ctxInitializerToSet, FREContextFinalizer* ctxFinalizerToSet);
void AirVideoFinalizer(void *extData);