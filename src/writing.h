#ifndef Writing_h
#define Writing_h

#include "ofMain.h"
#include "ofxOsc.h"


class Writing {

public:

    void setNewPoint(float, float);
    void setFirstPoint(float, float);
    void setLastPoint(float,float );
    void draw();
    void deleteIt();
    void changeColor(int,int,int);
    void setup(int, int, int);


    int red;
    int green;
    int blue;

    ofColor getColor();

    vector<ofPolyline> getVectorArray();
    vector<ofPolyline> allPolylines;

    ofPolyline polyline;
    ofPolyline prevPoint;

    ofPoint diff;
    ofPoint offset;

    int me_m_one;
    int me_p_one;

    float widthSmooth;
    float angleSmooth;

    float angle;
    float dist;



    ofMesh meshy;




};

#endif
