
void YAFGPreviewTop(){

    int offsetX=(400-(400*scaleX))/2;
    int offsetY=(240-(240*scaleY))/2;

    DrawRect(0+offsetX, 0+offsetY, 400, 240, YABlue,0);
    DrawRect(195+offsetX, 0+offsetY, 10, 240, YAOL,0);
    DrawRect(105+offsetX, 0+offsetY, 10, 240, YAOL,0);
    DrawRect(285+offsetX, 0+offsetY, 10, 240, YAOL,0);
    DrawRect(15+offsetX, 0+offsetY, 10, 240, YAOL,0);
    DrawRect(375+offsetX, 0+offsetY, 10, 240, YAOL,0);

    DrawRect(2*90-25, 200, 90, 35, YAOL,0);

    DrawCirc(200-5+offsetX, 100+5+offsetY*2, 30, YAShadow,0);
    DrawCirc(200+offsetX, 100+offsetY*2, 30, YAOL,0);
    DrawCirc(200+offsetX, 100+offsetY*2, 25, YAGreen,0);
}
void YAFGPreviewBottom(){
    int offset[2]={-40,-320};
    int offsetanim=260*((scale-.8)*5);


    C2D_DrawRectSolid(195+offset[0], 0,0, 10, offsetanim, YAOL);
    C2D_DrawRectSolid(105+offset[0], 0,0, 10, offsetanim, YAOL);
    C2D_DrawRectSolid(285+offset[0], 0,0, 10, offsetanim, YAOL);
}