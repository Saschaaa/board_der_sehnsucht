#include "generator.h"


void Generator::setup(string host ,int port){
    sender2.setup(host,port);
    }


void Generator::generator_min(){

    minimum_m.clear();
    float k;
    float l;
    k = 0.0;
    l = 0.0;

   for(int i = 0; i < 50; i++){
        //minimum.push_back(k, 10);
        k = ofRandom(0.0,1000.0);
        l = ofRandom(50.0,450.0);
        minimum_m.addFloatArg(k);

        minimum_m.addFloatArg(l);


   }
   minimum_m.addStringArg(";");
   minimum_m.addIntArg(60);
   minimum_m.addIntArg(60);
   minimum_m.addIntArg(60);
   minimum_m.addStringArg(";");

   cout << minimum_m.getNumArgs() << endl;
   sender2.sendMessage(minimum_m);
}



void Generator::generator_mid(){

    mid_m.clear();
    float k;
    float l;
    k = 0.0;
    l = 0.0;


    for(int i = 0; i < 500; i++){
        k = ofRandom(0.0,1000.0);
        l = ofRandom(50.0,450.0);
        if (mid_m.getNumArgs() < 500){
              mid_m.addFloatArg(k);
              mid_m.addFloatArg(l);
        }
        else if(mid_m.getNumArgs() >= 500){
            mid_m2.addFloatArg(k);
            mid_m2.addFloatArg(l);
        }


    }

    mid_m.addStringArg(";");
    mid_m2.addStringArg(";");
    mid_m.addIntArg(60);
    mid_m.addIntArg(60);
    mid_m.addIntArg(60);
    mid_m.addStringArg(";");


    cout << mid_m.getNumArgs() << endl;
    sender2.sendMessage(mid_m);
    sender2.sendMessage(mid_m2);
}

void Generator::generator_max(){

    maximum_m.clear();
    float k;
    k = 0.0;

    for(int i = 0; i < 5000 ; i++){
        maximum_m.addFloatArg(k);
        maximum_m.addFloatArg(10.0);
        k = k + 0.1;

    }



    cout << maximum_m.getNumArgs() << endl;
    sender2.sendMessage(maximum_m);

}
