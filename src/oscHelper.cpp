#include "oscHelper.h"

void oscHelper::setup(string host, int port){

    sender.setup(host, port);

}

void oscHelper::loadXML(){

     	if( XML.loadFile("address.xml") ){
		cout << "loaded" << endl;
	}else{
		cout << "not_loaded" << endl;
	}

	address = XML.getValue("SETTINGS:ADDRESS", "");

	cout << address << endl;

}



//-----SEHNSUCHTSGENERATOR(MIN)-----------

void oscHelper::generator_min(){

    min.clear();
    min.setAddress(address);

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

void oscHelper::generator_dynamisch(){

    min.clear();
    min.setAddress(address);

    amountLetters = ofRandom(2,8);
    for(int i = 0; i <= amountLetters; i++){

        amountPoints = ofRandom(10,90);

        if( min.getNumArgs()+amountPoints*2 > 400 ){

            sender.sendMessage(min);
            min.clear();
        }

        for(int i = 0; i <= amountPoints; i++){

            k = ofRandom(100,950);
            l = ofRandom(100,500);

            min.addFloatArg(k);
            min.addFloatArg(l);
        }
        min.addStringArg(";");
    }

    min.addStringArg("#");
    sender.sendMessage(min);
}


//-----SEHNSUCHTSGENERATOR(MID)-----------
void oscHelper::generator_mid(){

    mid_1.clear();
    mid_2.clear();
    mid_1.setAddress(address);
    mid_2.setAddress(address);

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

    max_1.setAddress(address);
    max_2.setAddress(address);
    max_3.setAddress(address);
    max_4.setAddress(address);

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
    m2.clear();
    m3.clear();
    m4.clear();
    m5.clear();
    m6.clear();
    m7.clear();
    m.setAddress(address);
    m2.setAddress(address);
    m3.setAddress(address);
    m4.setAddress(address);
    m5.setAddress(address);
    m6.setAddress(address);
    m7.setAddress(address);

    // Alle abgelegten Vektoren aus "allPolylines" laden
    for(vector< ofPolyline> ::iterator it = VectorArray.begin(); it != VectorArray.end(); ++it){

        vector<ofPoint> temp = it->getVertices();

        for(vector<ofPoint>::iterator it_point = temp.begin(); it_point != temp.end(); ++it_point){


            if(m.getNumArgs() < 400){

                  m.addFloatArg(it_point->x);
                  m.addFloatArg(it_point->y);

            }

            else if(m.getNumArgs() >= 399 && m2.getNumArgs() < 400) {

                 m2.addFloatArg(it_point->x);
                 m2.addFloatArg(it_point->y);

            }

            else if(m.getNumArgs() >= 399 && m2.getNumArgs() >=  399 && m3.getNumArgs() < 400){

                 m3.addFloatArg(it_point->x);
                 m3.addFloatArg(it_point->y);

            }

            else if(m.getNumArgs() >= 399 && m2.getNumArgs() >=  399 && m3.getNumArgs() >= 399 && m4.getNumArgs() < 400){

                 m4.addFloatArg(it_point->x);
                 m4.addFloatArg(it_point->y);

            }

            else if(m.getNumArgs() >= 399 && m2.getNumArgs() >=  399 && m3.getNumArgs() >= 399 && m4.getNumArgs() >= 399 && m5.getNumArgs() < 400){

                 m5.addFloatArg(it_point->x);
                 m5.addFloatArg(it_point->y);

            }

            else if(m.getNumArgs() >= 399 && m2.getNumArgs() >=  399 && m3.getNumArgs() >= 399 && m4.getNumArgs() >= 399 && m5.getNumArgs() >= 399 && m6.getNumArgs() < 400){

                 m6.addFloatArg(it_point->x);
                 m6.addFloatArg(it_point->y);

            }

            else if(m.getNumArgs() >= 399 && m2.getNumArgs() >=  399 && m3.getNumArgs() >= 399 && m4.getNumArgs() >= 399 && m5.getNumArgs() >= 399 && m6.getNumArgs() >= 399 && m7.getNumArgs() < 400){

                 m7.addFloatArg(it_point->x);
                 m7.addFloatArg(it_point->y);

            }



        }

        if(m.getNumArgs() < 400){

            m.addStringArg(";");

        }

        else if(m.getNumArgs() >= 399 && m2.getNumArgs() < 400){

            m2.addStringArg(";");

        }

        else if(m.getNumArgs() >= 399 && m2.getNumArgs() >= 399 && m3.getNumArgs() < 400){

            m3.addStringArg(";");
        }

        else if(m.getNumArgs() >= 399 && m2.getNumArgs() >= 399 && m3.getNumArgs() >=  399 && m4.getNumArgs() < 400){

            m4.addStringArg(";");
        }

         else if(m.getNumArgs() >= 399 && m2.getNumArgs() >=  399 && m3.getNumArgs() >= 399 && m4.getNumArgs() >= 399 && m5.getNumArgs() < 400){

                 m5.addStringArg(";");
            }

            else if(m.getNumArgs() >= 399 && m2.getNumArgs() >=  399 && m3.getNumArgs() >= 399 && m4.getNumArgs() >= 399 && m5.getNumArgs() >= 399 && m6.getNumArgs() < 400){

                 m6.addStringArg(";");

            }

             else if(m.getNumArgs() >= 399 && m2.getNumArgs() >=  399 && m3.getNumArgs() >= 399 && m4.getNumArgs() >= 399 && m5.getNumArgs() >= 399 && m6.getNumArgs() >= 399 && m7.getNumArgs() < 400){

                 m7.addStringArg(";");

            }


        /*if(m.getNumArgs() < 400){

            m.addStringArg(";");

        }

        else{

            m2.addStringArg(";");
        }*/



    }

    if(m.getNumArgs() < 400){

        m.addStringArg("#");
        sender.sendMessage(m);

    }

    else if(m.getNumArgs() >= 399 && m2.getNumArgs() < 400){

        m2.addStringArg("#");
        sender.sendMessage(m);
        sender.sendMessage(m2);

    }

    else if(m.getNumArgs() >= 399 && m2.getNumArgs()>= 399 && m3.getNumArgs() < 400){

        m3.addStringArg("#");
        sender.sendMessage(m);
        sender.sendMessage(m2);
        sender.sendMessage(m3);

    }

    else if(m.getNumArgs() >= 399 && m2.getNumArgs()>= 399 && m3.getNumArgs() >= 399 && m4.getNumArgs() < 400){

        m4.addStringArg("#");
        sender.sendMessage(m);
        sender.sendMessage(m2);
        sender.sendMessage(m3);
        sender.sendMessage(m4);

    }

     else if(m.getNumArgs() >= 399 && m2.getNumArgs() >=  399 && m3.getNumArgs() >= 399 && m4.getNumArgs() >= 399 && m5.getNumArgs() < 400){

        m5.addStringArg("#");
        sender.sendMessage(m);
        sender.sendMessage(m2);
        sender.sendMessage(m3);
        sender.sendMessage(m4);
        sender.sendMessage(m5);

            }

            else if(m.getNumArgs() >= 399 && m2.getNumArgs() >=  399 && m3.getNumArgs() >= 399 && m4.getNumArgs() >= 399 && m5.getNumArgs() >= 399 && m6.getNumArgs() < 400){

                 m6.addStringArg("#");
                 sender.sendMessage(m);
                sender.sendMessage(m2);
                sender.sendMessage(m3);
                sender.sendMessage(m4);
                sender.sendMessage(m5);
                sender.sendMessage(m6);


            }

             else if(m.getNumArgs() >= 399 && m2.getNumArgs() >=  399 && m3.getNumArgs() >= 399 && m4.getNumArgs() >= 399 && m5.getNumArgs() >= 399 && m6.getNumArgs() >= 399 && m7.getNumArgs() < 400){

                 m7.addStringArg("#");
                 sender.sendMessage(m);
                sender.sendMessage(m2);
                sender.sendMessage(m3);
                sender.sendMessage(m4);
                sender.sendMessage(m5);
                sender.sendMessage(m6);
                sender.sendMessage(m7);

            }

    //m.addStringArg("#");
    //sender.sendMessage(m);
   // sender.sendMessage(m2);

    cout << m.getNumArgs() << endl;
    cout << m2.getNumArgs() << endl;
    cout << m3.getNumArgs() << endl;

}









