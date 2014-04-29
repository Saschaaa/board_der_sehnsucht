#include "writing.h"


void Writing::setup(int r, int g, int b){

    red = r;
    green = g;
    blue = b;

}


void Writing::deleteIt(){

    allPolylines.clear();
    polyline.clear();

}

void Writing::deleteLast(){

    if(allPolylines.size() != 0){

        allPolylines.erase(allPolylines.end());

    }

}


vector< ofPolyline > Writing::getVectorArray(){

    return allPolylines;

}


void Writing::changeColor(int r, int g, int b){

    red = r;
    green = g;
    blue = b;

}


void Writing::setFirstPoint(float x_touch , float y_touch){

    polyline.addVertex(ofPoint(x_touch,y_touch));

}


ofColor Writing::getColor(){

    return ofColor(red, green, blue);

}


void Writing::setNewPoint(float x_touch , float y_touch){

    polyline.addVertex(ofPoint(x_touch,y_touch));

}


void Writing::setLastPoint(float x_touch, float y_touch){


if(polyline.size()){


    allPolylines.push_back( polyline.getSmoothed(2,1) );
    polyline.clear();

}
else{

    polyline.clear();
}
};


void Writing::draw(){

    ofSetColor(red,green,blue);
    polyline.getSmoothed(100, 20);
    meshy.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    meshy.clear();

    for (int i = 0;  i < polyline.getVertices().size(); i++){

        me_m_one = i-1;
        me_p_one = i+1;
        if (me_m_one < 0) me_m_one = 0;
        if (me_p_one ==  polyline.getVertices().size()) me_p_one =  polyline.getVertices().size()-1;
        diff = polyline.getVertices()[me_p_one] - polyline.getVertices()[me_m_one];
        angle = atan2(diff.y, diff.x);
        dist = diff.length();
        offset.x = cos(angle + PI/2) * 2;
        offset.y = sin(angle + PI/2) * 3;
        meshy.addVertex(  polyline.getVertices()[i] +  offset );
        meshy.addVertex(  polyline.getVertices()[i] -  offset );

    }

    meshy.draw();


    for(vector<ofPolyline> ::iterator it = allPolylines.begin(); it != allPolylines.end(); ++it){

        if(it->size()==1){

            ofFill();
            ofCircle(it->getVertices().back(), 10);

        }

        else{

            meshy.clear();

            for (int i = 0;  i < it->getVertices().size(); i++){

                me_m_one = i-1;
                me_p_one = i+1;
                if (me_m_one < 0) me_m_one = 0;
                if (me_p_one ==  it->getVertices().size()) me_p_one =  it->getVertices().size()-1;
                diff = it->getVertices()[me_p_one] - it->getVertices()[me_m_one];
                angle = atan2(diff.y, diff.x);
                dist = diff.length();
                offset;
                offset.x = cos(angle + PI/2) * 2;
                offset.y = sin(angle + PI/2) * 3;
                meshy.addVertex(  it->getVertices()[i] +  offset );
                meshy.addVertex(  it->getVertices()[i] -  offset );

            }

            meshy.draw();

        }

    }

}



