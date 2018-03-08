#define _CRT_SECURE_NO_DEPRECATE 

#include "goahead.h"
#include "main.h"

#define wfree(p) if (p) { free(p); } else

static int finished = 0;
//static void initPlatform();

static void ShowString(Webs *wp);

int StartMainServer(){
	//char *route = (char*)"/FlashDev/route.txt";
    //char *auth = (char*)"/FlashDev/auth.txt";
	//char *documents = (char*)"/FlashDev/web";

	char *route = (char*)"/data/goahead_demo/route.txt";
    char *auth = (char*)"/data/goahead_demo/auth.txt";
	char *documents = (char*)"/data/goahead_demo/web";
    LOGD("jni.StartMainServer(21)");  
    LOGD("%s(%d)\n", __FUNCTION__, __LINE__);
	//initPlatform();
	
    if (websOpen(documents, route) < 0) {
        error("Cannot initialize server. Exiting.");
        LOGD("Cannot initialize server. Exiting.");
        return -1;
    }
    LOGD("%s(%d)\n", __FUNCTION__, __LINE__);
    if (websLoad(auth) < 0) {
        error("Cannot load %s", auth);
        LOGD("Cannot load %s", auth);
        return -1;
    }
	websDefineAction("showString", ShowString);
        LOGD("%s(%d)\n", __FUNCTION__, __LINE__);
	char *endpoints = (char*)sclone((char*)"http://*:8082,https://*:5858");//"http://*:80,https://*:443"
	//char *endpoints = (char*)"http://*:80,https://*:443";
	char *tok;
	char *endpoint;
        LOGD("%s(%d)endpoints=%s\n", __FUNCTION__, __LINE__, endpoints);
	for (endpoint = stok(endpoints, ", \t", &tok); endpoint; endpoint = stok(NULL, ", \t,", &tok)) {
		if (websListen(endpoint) < 0) {
                        LOGD("%s(%d)websListen failed\n", __FUNCTION__, __LINE__);
			return -1;
		}
	}
        LOGD("%s(%d)\n", __FUNCTION__, __LINE__);
	wfree(endpoints);
	/////
	if (websGetBackground()) {
        //if (daemon(0, 0) < 0) {
        //    error("Cannot run as daemon");
        //    return -1;
        //}
    }
	
    websServiceEvents(&finished);
	printf("Instructed to exit");
    websClose();

	return 0;
}


static void ShowString(Webs *wp){
    WebsRoute *route;
	char result[64];
    assert(wp);
    route = wp->route;
    assert(route);
	sprintf(result, "I am ShowString : %s", websGetVar(wp, "str", ""));
	printf("%s : result=%s\n", __FUNCTION__, result);
	websWrite(wp,result);
	websDone(wp);
}