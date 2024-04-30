use rand::Rng;
// ground = 0, Robot = 1, Mud = 2
const LINE: usize = 8;
const COLUM: usize = 8;

fn main(){
    let mut map: [[i32; LINE]; COLUM] = [[0; LINE]; COLUM];
    map = lauch_bot (map);
    map = splash_mud(map);
    rende_frame(map);
    print!("FIM");
    print!("FIM");
}

fn find_mud(mut map: [[i32; LINE]; COLUM]) -> [[i32; LINE ]; COLUM ]{
    /*
    int lineMinusOne = line - 1;
    int columMinusOne = colum - 1;

    int found;
    int lineRobot;
    int columRobot;
    int tmpLine;
    int tmpColum;
    */
    let mut robot_location_x_y = bot_location(map);
    let mut line_robot = robot_location_x_y[0];
    let mut colum_robot = robot_location_x_y[1];

    let mut found = 0;
    while( found = 0){
        robot_location_x_y = bot_location(map);
        line_robot = robot_location_x_y[0];
        colum_robot = robot_location_x_y[1];

        found = 0;
        // Continuar apartir daqui
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

fn splash_mud(mut map: [[i32; LINE]; COLUM]) -> [[i32; LINE ]; COLUM ]{
    let mut line_mud_center = rand::thread_rng().gen_range(0..LINE);
    let mut colum_mud_center = rand::thread_rng().gen_range(0..COLUM);
    while map[line_mud_center ][colum_mud_center ] == 1{
        line_mud_center = rand::thread_rng().gen_range(0..LINE);
        colum_mud_center = rand::thread_rng().gen_range(0..COLUM);
    };
    map[line_mud_center ][colum_mud_center ] = 2;
    let mut mud_limit;
    let mut temp_local = 0;
    //UP
    mud_limit  = rand::thread_rng().gen_range(0..line_mud_center + 1);
    temp_local;
    temp_local = line_mud_center;
    while  temp_local > mud_limit {
        temp_local -= 1;
        if map[temp_local ][colum_mud_center ] != 1 {
            map[temp_local  ][colum_mud_center ] = 2;
        }
        rende_frame(map);
    }
    //DOWN
    mud_limit  = rand::thread_rng().gen_range(line_mud_center..LINE);
    temp_local;
    temp_local = line_mud_center;
    while  temp_local < mud_limit {
        temp_local += 1;
        if map[temp_local ][colum_mud_center ] != 1 {
            map[temp_local  ][colum_mud_center ] = 2;
        }
        rende_frame(map);
    }
    //LEFT
    mud_limit  = rand::thread_rng().gen_range(0..colum_mud_center + 1);
    temp_local;
    temp_local = colum_mud_center;
    while  temp_local > mud_limit {
        temp_local -= 1;
        if map[line_mud_center ][temp_local ] != 1 {
            map[line_mud_center  ][temp_local ] = 2;
        }
        rende_frame(map);
    }
    //RIGHT
    mud_limit  = rand::thread_rng().gen_range(colum_mud_center..COLUM);
    temp_local;
    temp_local = colum_mud_center;
    while  temp_local < mud_limit {
        temp_local += 1;
        if map[line_mud_center ][temp_local ] != 1 {
            map[line_mud_center  ][temp_local ] = 2;
        }
        rende_frame(map);
    }
    map
}

fn bot_location(map: [[i32; LINE ]; COLUM ]) -> [i32;2]{
    let mut robot_location_x_y: [i32;2] = [0,0];
    for tmp_line in 0..LINE {
        for tmp_colum in 0..COLUM {
            if map [tmp_line][tmp_colum] == 1{
                robot_location_x_y[0] = tmp_line as i32;
                robot_location_x_y[1] = tmp_colum as i32;
                return robot_location_x_y;
            };
        }
        }
    robot_location_x_y
}

fn lauch_bot(mut map: [[i32; LINE ]; COLUM ]) -> [[i32; LINE ]; COLUM ]{
    map [0][0] = 1;
    map
}

fn rende_frame (map: [[i32; LINE ]; COLUM ]){
    println!("- - -");
    for tmp_line in 0..LINE {
        for tmp_colum in 0..COLUM {
            match map[tmp_line][tmp_colum] {
                0 => print!("/"),
                1 => print!("+"),
                2 => print!("#"),
                _ => print!("Invalid choice"),
            }
        }
        println!("");
    }
}
