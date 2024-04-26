#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
// 0 = ground, 1 = Robot, 2 = Mud
#define line 4
#define colum 4
static int map[line][colum];
void splashMud();
void lauchBot();
void renderFrame();
void renderMud();
void renderRobotMovement();
void findMud ();
void controlTheBot ();
void controlBot(int lineLocated, int columLocated);
int main(){
    srand(time(NULL));
    lauchBot();
    //splashMud();
    map[0][2] = 2;
    map[2][2] = 2;
    map[2][1] = 2;
    map[2][3] = 2;
    map[2][0] = 2;


    renderFrame();
    findMud();
    renderFrame();
}
void cleanMud (int lineMud, int columMud){
    //printf("3*\n");
    int found = 0;
    int lineRobot = -1;
    int columRobot = -1;
    for ( int tmpLine = 0; tmpLine <= line && found == 0; tmpLine++ ) {
        for ( int tmpColum = 0 ; tmpColum <= colum && found == 0; tmpColum++ ) {
            //printf("%d %d: %d",tmpLine,tmpColum,map[tmpLine][tmpColum]);
            if(map[tmpLine][tmpColum] == 1){
                found = 1;
                lineRobot = tmpLine;
                columRobot = tmpColum;
            }
        }
    }
    if (lineRobot == -1 || columRobot == -1){
        renderRobotMovement();
        printf("Robot not found");
        int doll;
        scanf("%d",&doll);
    }
     //printf("[%d][%d]",lineRobot,columRobot);
    for(columRobot ;columRobot < columMud ; map[lineRobot][columRobot] = 0, columRobot++ , map[lineRobot][columRobot] = 1, renderRobotMovement()){
        //printf("render1");
        //renderRobotMovement();
        if(map[lineRobot][columRobot] == 2){
            map[lineRobot][columRobot] = 1;
        }
    }
    for(lineRobot ; lineRobot < lineMud ; map[lineRobot][columRobot] = 0, lineRobot++, map[lineRobot][columRobot] = 1, renderRobotMovement()){
        //printf("render2");
        //renderRobotMovement();
        if(map[lineRobot][columRobot] == 2){
            map[lineRobot][columRobot] = 1;
        }
    }

    for(columRobot ;columRobot > columMud ;map[lineRobot][columRobot] = 0, columRobot-- , map[lineRobot][columRobot] = 1,renderRobotMovement() ){
        //printf("render1");
        //renderRobotMovement();
        if(map[lineRobot][columRobot] == 2){
            map[lineRobot][columRobot] = 1;
        }
    }
}

void findMud (){
    int noMud;
    do{
        noMud = 1;
        for ( int tmpLine = 0; tmpLine <= line; tmpLine++ ) {
            //printf("UNO*\n");
            for ( int tmpColum = 0 ; tmpColum <= colum; tmpColum++ ) {
                //printf("DOS[%d][%d]\n",tmpLine,tmpColum);
                //printf("L->%dC->%d\n",line,colum);
                //renderFrame();
                //usleep(300000);
                if(map[tmpLine][tmpColum] == 2){
                    cleanMud(tmpLine,tmpColum);
                    noMud = 0;
                }
            }
        }
    }while(noMud != 1);
}
void lauchBot(){
    int sucessFlag = 0;
    for ( int tmpLine = 0; tmpLine <= line && sucessFlag == 0 ; tmpLine++ ) {
        for ( int tmpColum = 0 ; tmpColum <= colum && sucessFlag == 0 ; tmpColum++ ) {
            if(map[tmpLine][tmpColum] == 0){
               map[tmpLine][tmpColum] = 1;
               sucessFlag = 1;
            }
        }
    }
}
void splashMud(){
    int localLine = line;
    int localColum = colum;
    int lineMudCenter = rand() % localLine;
    int columMudCenter = rand() % localColum;
    localLine--;
    localColum--;
    //up
    int tmpMax = rand() % (lineMudCenter + 1);
    for (int tempLocal =  lineMudCenter; tempLocal >= tmpMax ; tempLocal--){
        map[tempLocal][columMudCenter] = 2;
        renderMud();
    }
    //Down
    tmpMax = rand() % (localLine - lineMudCenter + 1);
    tmpMax = tmpMax + lineMudCenter;
    for(int tempLocal =  lineMudCenter; tempLocal <= tmpMax ; tempLocal++){
        map[tempLocal][columMudCenter] = 2;
        renderMud();
    }
    //Left
    tmpMax = rand() % (columMudCenter + 1);
    for (int tempLocal =  columMudCenter; tempLocal >= tmpMax ; tempLocal--){
        map[lineMudCenter][tempLocal] = 2;
        renderMud();
    }
    //Right
    tmpMax = rand() % (localColum - columMudCenter + 1);
    tmpMax = tmpMax + columMudCenter;
    for(int tempLocal =  columMudCenter; tempLocal <= tmpMax ; tempLocal++){
        map[lineMudCenter][tempLocal] = 2;
        renderMud();
    }
}
void renderRobotMovement(){
    usleep(1000000);
    renderFrame();
}
void renderMud(){
    usleep(300000);
    renderFrame();
}
void renderFrame(){
    int localLine = line;
    int localColum = colum;
    localLine--;
    localColum--;
    printf("\n- - -\n");
    for ( int tmpLine = 0; tmpLine <= localLine ; tmpLine++ ) {
        //printf("%d|",tmpLine);
        for ( int tmpColum = 0 ; tmpColum <= localColum ; tmpColum++ ){
            switch (map[ tmpLine ][ tmpColum ]){
                case 0:
                    printf("/");
                    break;
                case 1:
                    printf("R");
                    break;
                case 2:
                    printf("#");
                    break;
            }
        }
        printf("\n");
    }
}
