#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
// ground = 0, Robot = 1, Mud = 2
// Testar se lama se espalha para borda ( se algo desliza para bordas validas)
// Testar se o aleatorio realmente cai em tudo
#define line 8
#define colum 8
static int map[line][colum];
int countNameLetter = 5;
void splashMud();
void lauchBot();
void renderFrame(int renderMode);
void renderMud();
void renderRobotMovement();
void findMud ();
void controlTheBot ();
void controlBot(int lineLocated, int columLocated);
int main(){
    srand ( (unsigned int)time(NULL) );
    lauchBot();
    int loop = 1, loop1 = 1;
    while(loop == loop1){
        splashMud();
        //renderFrame( 0 );
        findMud();
        //renderFrame( 0 );
    }
    printf("FIM|");
    printf("FIM");
}
void cleanMud (int lineMud, int columMud){
    int lineMinusOne = line - 1;
    int columMinusOne = colum - 1;

    int found;
    int lineRobot;
    int columRobot;
    int tmpLine;
    int tmpColum;
    // Atenção abaixo
    found = 0;
    lineRobot = -1;
    columRobot = -1;
    for ( tmpLine = 0; tmpLine <= lineMinusOne && found == 0; tmpLine++ ) {
        for ( tmpColum = 0 ; tmpColum <= columMinusOne && found == 0; tmpColum++ ) {
            if(map[tmpLine][tmpColum] == 1){
                lineRobot = tmpLine;
                columRobot = tmpColum;
                found = 1;
            }
        }
    }
    while (columRobot < columMud){
        //renderRobotMovement();
        //printf("Perfect Compare");
        map[lineRobot][columRobot] = 0;
        columRobot++;
        map[lineRobot][columRobot] = 1;
        renderRobotMovement();
    }
    while (lineRobot < lineMud){   
        //renderRobotMovement();
        //printf("Perfect Compare");
        map[lineRobot][columRobot] = 0;
        lineRobot++;
        map[lineRobot][columRobot] = 1;
        renderRobotMovement();
        }
    while (columRobot > columMud){   
        //renderRobotMovement();
        //printf("Perfect Compare");
        map[lineRobot][columRobot] = 0;
        columRobot--;
        map[lineRobot][columRobot] = 1;
        renderRobotMovement();
    }
    while (lineRobot > lineMud){   
        //renderRobotMovement();
        //printf("Perfect Compare");
        map[lineRobot][columRobot] = 0;
        lineRobot--;
        map[lineRobot][columRobot] = 1;
        renderRobotMovement();
        }
}

void findMud (){
    //int noMud;
    int lineMinusOne = line - 1;
    int columMinusOne = colum - 1;

    int found;
    int lineRobot;
    int columRobot;
    int tmpLine;
    int tmpColum;
    do{
    found = 0;
    lineRobot = -1;
    columRobot = -1;
    for ( tmpLine = 0; tmpLine <= lineMinusOne && found == 0; tmpLine++ ) {
        for ( tmpColum = 0 ; tmpColum <= columMinusOne && found == 0; tmpColum++ ) {
            if(map[tmpLine][tmpColum] == 1){
                found = 1;
                lineRobot = tmpLine;
                columRobot = tmpColum;
            }
        }
    }
    int lineNextMud = -999;// Deletar
    int columNextMud = -999;// Deletar

    found = 0;
    for( tmpColum = columRobot; tmpColum <= columMinusOne && found == 0;tmpColum++){
        if (map[lineRobot][tmpColum] == 2){
            found = 1;
            lineNextMud = lineRobot;
            columNextMud = tmpColum;
        }
    }
    if(found == 0){
    for( tmpLine = lineRobot; tmpLine <= lineMinusOne && found == 0; tmpLine++){
        if (map[tmpLine][columRobot] == 2){
            found = 1;
            lineNextMud = tmpLine;
            columNextMud = columRobot;            
        }
    }
    }
    if(found == 0){
    for( tmpColum = columRobot; tmpColum >= 0 && found == 0;tmpColum--){
        if (map[lineRobot][tmpColum] == 2){
            found = 1;
            lineNextMud = lineRobot;
            columNextMud = tmpColum;            
        }
    }
    }
    if(found == 0){
    for( tmpLine = lineRobot; tmpLine >= 0 && found == 0; tmpLine--){
        if (map[tmpLine][columRobot] == 2){
            found = 1;
            lineNextMud = tmpLine;
            columNextMud = columRobot;            
        }
        }
    }
    if (found == 1){
        cleanMud(lineNextMud,columNextMud);
    }
    }while(found == 1);
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
    int lineMudCenter;
    int columMudCenter;
    do{
        lineMudCenter = rand() % localLine; // Nessa regra já se 'subtrai 1'
        columMudCenter = rand() % localColum;
    }while(map[lineMudCenter][columMudCenter] == 1);
    localLine--;
    localColum--;
    //up
    int tmpMax = rand() % (lineMudCenter + 1);
    for (int tempLocal =  lineMudCenter; tempLocal >= tmpMax ; tempLocal--){
        if(map[tempLocal][columMudCenter] != 1){
            map[tempLocal][columMudCenter] = 2;
        }
        renderMud();
    }
    //Down
    tmpMax = rand() % (localLine - lineMudCenter + 1);
    tmpMax = tmpMax + lineMudCenter;
    for(int tempLocal =  lineMudCenter; tempLocal <= tmpMax ; tempLocal++){
        if(map[tempLocal][columMudCenter] != 1){
            map[tempLocal][columMudCenter] = 2;
        }
        renderMud();
    }
    //Left
    tmpMax = rand() % (columMudCenter + 1);
    for (int tempLocal =  columMudCenter; tempLocal >= tmpMax ; tempLocal--){
        if(map[lineMudCenter][tempLocal] != 1){
            map[lineMudCenter][tempLocal] = 2;
        }
        renderMud();
    }
    //Right
    tmpMax = rand() % (localColum - columMudCenter + 1);
    tmpMax = tmpMax + columMudCenter;
    for(int tempLocal =  columMudCenter; tempLocal <= tmpMax ; tempLocal++){
        if(map[lineMudCenter][tempLocal] != 1){
            map[lineMudCenter][tempLocal] = 2;
        }
        renderMud();
    }
}
void renderRobotMovement(){
    usleep(1000000);
    renderFrame( 0 );
}
void renderMud(){
    usleep(300000);
    renderFrame( 1 );
}
//0 padrão, Mantém apenas a inicial "R"
void renderFrame(int renderMode ){
    int localLine = line;
    int localColum = colum;
    localLine--;
    localColum--;
    printf("\n- - -\n");
    for ( int tmpLine = 0; tmpLine <= localLine ; tmpLine++ ) {
        for ( int tmpColum = 0 ; tmpColum <= localColum ; tmpColum++ ){
            switch (map[ tmpLine ][ tmpColum ]){
                case 0:
                    printf("/");
                    break;
                case 1:
                    if (renderMode == 1){
                        countNameLetter = 1;
                    }
                    switch (countNameLetter){
                        case 1: 
                        printf("+");
                        break;
                        case 2: 
                        printf("-");
                        countNameLetter = 0;
                        }
                        countNameLetter++;
                    break;
                case 2:
                    printf("#");
                    break;
            }
        }
        printf("\n");
    }
}
