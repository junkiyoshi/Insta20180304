#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(230);
	ofSetWindowTitle("Insta");

	ofSetColor(39);
	//ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->drawCircle(2, ofPoint(ofGetWidth() / 4, ofGetHeight() / 4), ofGetWidth() / 4);
	this->drawCircle(3, ofPoint(ofGetWidth() / 4 * 3, ofGetHeight() / 4), ofGetWidth() / 4);
	this->drawCircle(4, ofPoint(ofGetWidth() / 4, ofGetHeight() / 4 * 3), ofGetWidth() / 4);
	this->drawCircle(5, ofPoint(ofGetWidth() / 4 * 3, ofGetHeight() / 4 * 3), ofGetWidth() / 4);
}

//--------------------------------------------------------------
void ofApp::drawCircle(int level, ofPoint point, float radius) {

	if (level > 0) {

		float deg = ofGetFrameNum() * (6 - level);
		ofPoint point_1 = ofPoint(point.x + (radius / 2) * cos(deg * DEG_TO_RAD), point.y + (radius / 2) * sin(deg * DEG_TO_RAD));
		ofPoint point_2 = ofPoint(point.x - (radius / 2) * cos(deg * DEG_TO_RAD), point.y - (radius / 2) * sin(deg * DEG_TO_RAD));

		this->drawCircle(level - 1, point_1, radius / 2);
		this->drawCircle(level - 1, point_2, radius / 2);
	}
	else {


		ofPushMatrix();
		ofTranslate(point);

		ofBeginShape();
		for (int deg = 0; deg <= 360; deg += 1) {

			float x = radius * cos(deg * DEG_TO_RAD);
			float y = radius * sin(deg * DEG_TO_RAD);

			ofVertex(x, y);
		}
		ofEndShape();

		ofPopMatrix();
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}