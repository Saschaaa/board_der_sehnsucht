#include "oscHelper.h"

void oscHelper::setup(string host, int port){

    sender.setup(host, port);

}



//-----SEHNSUCHTSGENERATOR(MIN)-----------

void oscHelper::generator_min(){

    min.clear();
    min.setAddress("/board2");

    for(int i = 0; i <= 100; i++){

        k = ofRandom(0,1000);
        l = ofRandom(0,800);

        min.addFloatArg(k);
        min.addFloatArg(l);

    }

    min.addStringArg(";");
    min.addStringArg("#");
    sender.sendMessage(min);
}


//-----SEHNSUCHTSGENERATOR(MID)-----------
void oscHelper::generator_mid(){

    mid_1.clear();
    mid_2.clear();
    mid_1.setAddress("/board2");
    mid_2.setAddress("/board2");

    for(int i = 0; i <= 400; i++){

        k = ofRandom(0,1000);
        l = ofRandom(0,800);

        if(mid_1.getNumArgs() <= 500){

            mid_1.addFloatArg(k);
            mid_1.addFloatArg(l);

        }
        else{

            mid_2.addFloatArg(k);
            mid_2.addFloatArg(l);

        }

    }

    mid_2.addStringArg(";");
    mid_2.addStringArg("#");
    sender.sendMessage(mid_1);
    sender.sendMessage(mid_2);

}

//-----SEHNSUCHTSGENERATOR(MAX)-----------
void oscHelper::generator_max(){

    max_1.clear();
    max_2.clear();
    max_3.clear();
    max_4.clear();

    max_1.setAddress("/board2");
    max_2.setAddress("/board2");
    max_3.setAddress("/board2");
    max_4.setAddress("/board2");

    for(int i = 0; i <= 1000; i++){

        k = ofRandom(0,1000);
        l = ofRandom(0,800);

        if(max_1.getNumArgs() <= 500){

            max_1.addFloatArg(k);
            max_1.addFloatArg(l);

        }

        else if(max_1.getNumArgs() >= 500 && max_2.getNumArgs() <= 500){

            max_2.addFloatArg(k);
            max_2.addFloatArg(l);

        }

        else if(max_1.getNumArgs() >= 500 && max_2.getNumArgs() >= 500 && max_3.getNumArgs() <= 500){

            max_3.addFloatArg(k);
            max_3.addFloatArg(l);

        }

        else{

            max_4.addFloatArg(k);
            max_4.addFloatArg(l);

        }

    }


    max_4.addStringArg(";");
    max_4.addStringArg("#");
    sender.sendMessage(max_1);
    sender.sendMessage(max_2);
    sender.sendMessage(max_3);
    sender.sendMessage(max_4);

}



//-----SEHNSUCHT VERSCHICKEN------
void oscHelper::sendVectorArray(  vector< ofPolyline >  VectorArray, ofColor color, int colorInd ){

    m.clear();
    m.setAddress("/board2");

    // Alle abgelegten Vektoren aus "allPolylines" laden
    for(vector< ofPolyline> ::iterator it = VectorArray.begin(); it != VectorArray.end(); ++it){

        vector<ofPoint> temp = it->getVertices();

        for(vector<ofPoint>::iterator it_point = temp.begin(); it_point != temp.end(); ++it_point){

            m.addFloatArg(it_point->x);
            m.addFloatArg(it_point->y);

        }

        m.addStringArg(";");

    }

    m.addStringArg(";");
    m.addStringArg("#");
    sender.sendMessage(m);
    cout << m.getNumArgs() << endl;

}









