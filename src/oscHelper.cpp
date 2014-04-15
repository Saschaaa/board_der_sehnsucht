#include "oscHelper.h"

void oscHelper::setup(string host, int port){

    sender.setup(host, port);

}



//-----SEHNSUCHTSGENERATOR(MIN)-----------

void oscHelper::generator_min(){

    min.clear();
    min.setAddress("/board1");

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
<<<<<<< HEAD
    min.setAddress("/board2");
=======
    min.setAddress("/board1");
>>>>>>> 2de6221aa23d6a1c9583950ffacac44e40108c60

    amountLetters = ofRandom(2,8);
    for(int i = 0; i <= amountLetters; i++){

        amountPoints = ofRandom(10,90);

<<<<<<< HEAD
        if( min.getNumArgs()+amountPoints*2 > 400 ){

            sender.sendMessage(min);
            min.clear();
=======
        if( min.getNumArgs() + amountPoints * 2 > 400 ){

            sender.sendMessage(min);
            min.clear();

>>>>>>> 2de6221aa23d6a1c9583950ffacac44e40108c60
        }

        for(int i = 0; i <= amountPoints; i++){

<<<<<<< HEAD
            k = ofRandom(100,950);
=======
            k = ofRandom(100,960);
>>>>>>> 2de6221aa23d6a1c9583950ffacac44e40108c60
            l = ofRandom(100,500);

            min.addFloatArg(k);
            min.addFloatArg(l);
<<<<<<< HEAD
=======

>>>>>>> 2de6221aa23d6a1c9583950ffacac44e40108c60
        }
        min.addStringArg(";");
    }

    min.addStringArg("#");
    sender.sendMessage(min);
<<<<<<< HEAD
=======


>>>>>>> 2de6221aa23d6a1c9583950ffacac44e40108c60
}


//-----SEHNSUCHTSGENERATOR(MID)-----------
void oscHelper::generator_mid(){

    mid_1.clear();
    mid_2.clear();
    mid_1.setAddress("/board1");
    mid_2.setAddress("/board1");

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

    max_1.setAddress("/board1");
    max_2.setAddress("/board1");
    max_3.setAddress("/board1");
    max_4.setAddress("/board1");

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
<<<<<<< HEAD
   // m3.clear();
    m.setAddress("/board2");
    m2.setAddress("/board2");
   // m3.setAddress("/board2");
=======
    m.setAddress("/board1");
    m2.setAddress("/board1");
>>>>>>> 2de6221aa23d6a1c9583950ffacac44e40108c60

    // Alle abgelegten Vektoren aus "allPolylines" laden
    for(vector< ofPolyline> ::iterator it = VectorArray.begin(); it != VectorArray.end(); ++it){

        vector<ofPoint> temp = it->getVertices();

        for(vector<ofPoint>::iterator it_point = temp.begin(); it_point != temp.end(); ++it_point){

<<<<<<< HEAD

            if(m.getNumArgs() < 400){

                  m.addFloatArg(it_point->x);
                  m.addFloatArg(it_point->y);

=======
            if(m.getNumArgs() < 400){

                m.addFloatArg(it_point->x);
                m.addFloatArg(it_point->y);
>>>>>>> 2de6221aa23d6a1c9583950ffacac44e40108c60
            }

            else{

<<<<<<< HEAD
                 m2.addFloatArg(it_point->x);
                 m2.addFloatArg(it_point->y);

            }



        }

        if(m.getNumArgs() < 400){

            m.addStringArg(";");

        }

        else{

            m2.addStringArg(";");

        }


        /*if(m.getNumArgs() < 400){

            m.addStringArg(";");

        }

        else{

            m2.addStringArg(";");
        }*/

=======
                m2.addFloatArg(it_point->x);
                m2.addFloatArg(it_point->y);
            }

        }

        //m.addStringArg(";");

        if(m.getNumArgs() < 400){

            m.addStringArg(";");

        }

        else{

            m2.addStringArg(";");

        }
>>>>>>> 2de6221aa23d6a1c9583950ffacac44e40108c60


    }

<<<<<<< HEAD
=======


>>>>>>> 2de6221aa23d6a1c9583950ffacac44e40108c60
    if(m.getNumArgs() < 400){

        m.addStringArg("#");
        sender.sendMessage(m);
<<<<<<< HEAD

    }

    else{

        m2.addStringArg("#");
        sender.sendMessage(m);
        sender.sendMessage(m2);

    }


    //m.addStringArg("#");
    //sender.sendMessage(m);
   // sender.sendMessage(m2);

    cout << m.getNumArgs() << endl;
    cout << m2.getNumArgs() << endl;
=======
    }

    else{

        m2.addStringArg("#");
        sender.sendMessage(m);
        sender.sendMessage(m2);

    }

/*
    m2.addStringArg(";");
    m2.addStringArg("#");
    sender.sendMessage(m);
    sender.sendMessage(m2);
    cout << m.getNumArgs() << endl;
    */
>>>>>>> 2de6221aa23d6a1c9583950ffacac44e40108c60

}









