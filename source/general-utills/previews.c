
void YAFGPreviewTop(){

    int offsetX=((400-(400*scaleX))/2)+pos;
    int offsetXBG=offsetX+pos;
    int offsetY=(240-(240*scaleY))/2;

    DrawRect(0+offsetXBG, 0+offsetY, 400, 240, YABlue,0);
    DrawRect(195+offsetXBG, 0+offsetY, 10, 240, YAOL,0);
    DrawRect(105+offsetXBG, 0+offsetY, 10, 240, YAOL,0);
    DrawRect(285+offsetXBG, 0+offsetY, 10, 240, YAOL,0);
    DrawRect(15+offsetXBG, 0+offsetY, 10, 240, YAOL,0);
    DrawRect(375+offsetXBG, 0+offsetY, 10, 240, YAOL,0);

    DrawRect(2*90-25+pos*1.5, 200+pos/2, 90, 35, YAOL,0);

    DrawCirc(200-5+offsetX+pos*2, 100+5+offsetY*2, 30, YAShadow,0);
    DrawCirc(200+offsetX+pos*2, 100+offsetY*2, 30, YAOL,0);
    DrawCirc(200+offsetX+pos*2, 100+offsetY*2, 25, YAGreen,0);
}
void YAFGPreviewBottom(){
    int offset[2]={-40,-320};
    int offsetanim=260*((scale-.8)*5);


    C2D_DrawRectSolid(195+offset[0], 0,0, 10, offsetanim, YAOL);
    C2D_DrawRectSolid(105+offset[0], 0,0, 10, offsetanim, YAOL);
    C2D_DrawRectSolid(285+offset[0], 0,0, 10, offsetanim, YAOL);
}