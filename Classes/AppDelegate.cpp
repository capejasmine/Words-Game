#include "AppDelegate.h"
#include "GameController.hpp"


USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }
    
    glview->setDesignResolutionSize(960, 640, ResolutionPolicy::NO_BORDER);

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    // add resource search paths
    std::vector<std::string> paths;
    paths.push_back("fonts/");
    paths.push_back("particle/");
    paths.push_back("public/");
    paths.push_back("sound/");
    paths.push_back("studio/");
    paths.push_back("studio/Animation");
    paths.push_back("studio/UI");
    paths.push_back("game/chinese/");
    paths.push_back("game/listen/");
    paths.push_back("game/select/");
    paths.push_back("game/view/");
    paths.push_back("game");
    
    
    FileUtils::getInstance()->setSearchPaths(paths);

    // create a scene. it's an autorelease object
    
    xGAME->enterHomeScene();

    // run

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
