#include <graphics.h>
#include <winbgim.h>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

// Function to speak text (Windows only)
void speak(const char* text) {
    string cmd = "powershell -NoProfile -Command \"Add-Type -AssemblyName System.Speech; ";
    cmd += "(New-Object System.Speech.Synthesis.SpeechSynthesizer).Speak('";
    cmd += text;
    cmd += "')\"";
    system(cmd.c_str());
}

// Draw left-hand menu
void drawMenu() {
    setcolor(WHITE);

    // Circle
    circle(70, 50, 25);
    outtextxy(50, 76, (char*)"Circle");

    // Rectangle
    rectangle(38, 115, 103, 155);
    outtextxy(40, 160, (char*)"Rectangle");

    // Triangle
    line(45, 240, 75, 195);
    line(75, 195, 105, 240);
    line(45, 240, 105, 240);
    outtextxy(50, 246, (char*)"Triangle");

    // Oval
    ellipse(75, 304, 0, 360, 33, 23);
    outtextxy(58, 330, (char*)"Oval");

    // Square
    rectangle(50, 370, 94, 410);
    outtextxy(50, 415, (char*)"Square");
}

// Draw shapes (with optional color fill)
void draw(bool circleBold, bool rectBold, bool triBold, bool ovalBold, bool squareBold) {
    setcolor(WHITE);
    line(150, 0, 150, 600); // Divider line

    // Circle
    if(circleBold) {
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        fillellipse(350, 400, 20, 20);
    } else {
        setcolor(WHITE);
        circle(350, 400, 20);
    }

    // Circle
    if(circleBold) {
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        fillellipse(450, 400, 20, 20);
    } else {
        setcolor(WHITE);
        circle(450, 400, 20);
    }
    // Oval
    if(ovalBold) {
        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        fillellipse(600, 300, 50, 100);
    } else {
        setcolor(WHITE);
        ellipse(600, 300, 0, 360, 50, 100);
    }

     if(ovalBold) {
        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        fillellipse(750,350, 30, 60);
    } else {
        setcolor(WHITE);
        ellipse(750,350, 0, 360, 30, 60);
    }
    
    // Rectangle 
    if(rectBold) {
        setcolor(MAGENTA);
        setfillstyle(SOLID_FILL, MAGENTA);
        bar(590,405,610,590);
    } else {
        setcolor(WHITE);
        rectangle(590,405,610,590);
    }

    //RECTANGLE
    if(rectBold) {
        setcolor(MAGENTA);
        setfillstyle(SOLID_FILL, MAGENTA);
        bar(743,415,757,590);
    } else {
        setcolor(WHITE);
        rectangle(743,415,757,590);
    }


    // Rectangle 
    if(rectBold) {
        setcolor(MAGENTA);
        setfillstyle(SOLID_FILL, MAGENTA);
        bar(370, 450, 430, 550);
    } else {
        setcolor(WHITE);
        rectangle(370, 450, 430, 550);
    }

    // Triangle 
    if(triBold) {
        setcolor(LIGHTRED);
        setfillstyle(SOLID_FILL, LIGHTRED);
        int points[] = {280, 340, 400, 200, 520, 340, 280, 340};
        fillpoly(4, points);
    } else {
        setcolor(WHITE);
        line(280,340,400,200);
        line(400,200,520,340);
        line(520,340,280,340);
    }

    // Square (Scarf)
    if(squareBold) {
        setcolor(LIGHTBLUE);
        setfillstyle(SOLID_FILL,LIGHTBLUE);
        bar(300, 350, 500, 550);
    } else {
        setcolor(WHITE);
        rectangle(300, 350, 500, 550);
    }
}

// Detect mouse clicks on menu items
void checkClick(int x, int y, bool &circleBold, bool &rectBold, bool &triBold, bool &ovalBold, bool &squareBold) {
    circleBold = rectBold = triBold = ovalBold = squareBold = false;

    if(x>=45 && x<=95 && y>=30 && y<=70){
        circleBold = true;
        speak("Circle");
    }
    else if(x>=40 && x<=100 && y>=115 && y<=155){
        rectBold = true;
        speak("Rectangle");
    }
    else if(x>=45 && x<=105 && y>=195 && y<=240){
        triBold = true;
        speak("Triangle");
    }
    else if(x>=40 && x<=100 && y>=280 && y<=330){
        ovalBold = true;
        speak("Oval");
    }
    else if(x>=50 && x<=94 && y>=370 && y<=410){
        squareBold = true;
        speak("Square");
    }
}

int main() {
    initwindow(800, 600, "Interactive Shapes with Color");

    bool circleBold=false, rectBold=false, triBold=false, ovalBold=false, squareBold=false;

    drawMenu();
    draw(circleBold, rectBold, triBold, ovalBold, squareBold);

    int x, y;
    while(true) {
        if(ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            checkClick(x, y, circleBold, rectBold, triBold, ovalBold, squareBold);
            cleardevice();
            drawMenu();
            draw(circleBold, rectBold, triBold, ovalBold, squareBold);
        }
        if(kbhit()) break;
    }

    closegraph();
    return 0;
}
