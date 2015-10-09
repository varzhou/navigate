﻿#include <iostream>
#include <vector>
#include <cstring>
#include <list>

#include "../src/paka_api.h"
#include "../src/navigate_defines.h"
using namespace std;

void test( int id1, int id2 )
{
    cout<<"From: "<<id1<<" To: "<<id2<<endl;

    NavPoint start;
    NavPoint end;

    start.id = id1;
    end.id = id2;

    PointArray ret  = getBestPath(&start, &end);

    int num = ret.num;
    NavPoint* p = ret.pts;
    for (int i = 0; i < num; ++i) {
        NavPoint e = p[i];
        cout << e.id << " " << GetTips(e.attr) << endl;
    }
    cout<<endl;
}

void test_any(int x, int y, int floornumber, int id2)
{

    NavPoint start;
    NavPoint end;

    start.x = x;
    start.y = y;
    start.floor = floornumber;
    start.id = -1;

    end.id = id2;

    PointArray ret  = getBestPath(&start, &end);

    int num = ret.num;
    NavPoint* p = ret.pts;
    for (int i = 0; i < num; ++i) {
        NavPoint e = p[i];
        cout << e.id << " " << GetTips(e.attr) << endl;

    }
    cout<<endl;
}


void test_navigate() {
    //加载地图路径点文件
    loadPathInfo("F:\\mg(xn).i2");

    // test_any(1083, 590, 3, 30001);

    test(30083,-10018);
    cout<<endl;
    /*
    //设置导航起点与终点
    test(30001,30045);
    cout<<endl;

    test(30021,30043);
    cout<<endl;

    test(30011,30025);
    cout<<endl;

    test(30085,30086);
    cout<<endl;
*/
}


void test_wifi_location_read_file() {
   // wloc.LoadWifiFile("/home/bukp/temp/wfinger.f");
    // wloc.LoadWifiFile("F:\\_temp\\wfinger.f");
}


void test_wifi_location_jduge_which_floor() {
    /*
    RealTimeFinger *f1 = new RealTimeFinger("d0c7c06f7194", -54);
    RealTimeFinger *f2 = new RealTimeFinger("147590e10142", -64);
    RealTimeFinger *f3 = new RealTimeFinger("78d38dbcbc74", -64);
    RealTimeFinger *f4 = new RealTimeFinger("bcd17750b46e", -67);
    RealTimeFinger *f5 = new RealTimeFinger("a8574e0590c0", -69);
    RealTimeFinger *f6 = new RealTimeFinger("a8ad3dc0f998", -70);
    RealTimeFinger *f7 = new RealTimeFinger("78d38dbcbc78", -70);
    RealTimeFinger *f8 = new RealTimeFinger("8089177e8038", -72);
    RealTimeFinger *f9 = new RealTimeFinger("08107692b1a9", -73);
    RealTimeFinger *f10 = new RealTimeFinger("e4d332bdad46", -73);
    RealTimeFinger *f11 = new RealTimeFinger("ec26ca38f68e", -74);
    RealTimeFinger *f12 = new RealTimeFinger("80891724fed8", -75);
    RealTimeFinger *f13 = new RealTimeFinger("60bb0c1f38ec", -75);
    RealTimeFinger *f14 = new RealTimeFinger("d4ee070f9736", -75);
    RealTimeFinger *f15 = new RealTimeFinger("38e595b271a9", -76);

    RealTimeFinger** fingers = new RealTimeFinger*[15] {
          f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15
    };
    // string floorcode =  wloc.LocationBuildingFloor(fingers, 15);
    //wloc.LocationFloorPoint(floorcode.c_str(), fingers, 15);
    */
}


int main()
{
   //test_wifi_location_read_file();
   //test_wifi_location_jduge_which_floor();
   loadWifiInfo("F:\\_temp\\wfinger.f");
   const char* bssids = "14759071f8b4,-44;bcd17798c642,-46;08107692b1a9,-48;20c9d0188cdc,-48;78d38dbcbc74,-55;9c216ae323a0,-55;80891724fed8,-59;78d38dbcbc78,-59;d0c7c00bbb5a,-59;54e6fc22046a,-59;202bc19f3639,-61;147590dc8346,-61;d0c7c08a440f,-79;b85510716928,-94;b85510716929,-94";
   WifiMultiPoint pp = doLocateTest(bssids);
   //test_navigate();
   return 0;
}

