use rand::Rng;
// ground = 0, Robot = 1, Mud = 2
// Testar se lama se espalha para borda ( se algo desliza para bordas validas)
// Testar se o aleatorio realmente cai em tudo
const LINE: i32 = 4;
const COLUM: i32 = 4;

fn main(){
    let mut map: [[i32; LINE as usize]; COLUM as usize] = [[0; LINE as usize]; COLUM as usize];
    //map = lauch_bot (map);
    map = splash_mud(map);
    //rende_frame(/* 0,*/ map);
    print!("FIM");
    print!("FIM");
}

fn splash_mud(mut map: [[i32; LINE as usize]; COLUM as usize]) -> [[i32; LINE as usize]; COLUM as usize]{

    let mut line_mud_center = rand::thread_rng().gen_range(0..LINE);
    let mut colum_mud_center = rand::thread_rng().gen_range(0..COLUM);
/*
    while map[line_mud_center as usize][colum_mud_center as usize] == 1{
        line_mud_center = rand::thread_rng().gen_range(0..LINE);
        colum_mud_center = rand::thread_rng().gen_range(0..COLUM);
    };
*/
    // LOCAL ALEATORIO ESCOLHIDO
    line_mud_center = 1;
    colum_mud_center = 1;
    //
    //UP
    //let mut temp_max = rand::thread_rng().gen_range(1..LINE);
    let mut temp_local;
    temp_local = line_mud_center;

    //
    let mut temp_max = 4;
    println!("line_mud_center:{}\ncolum_mud_center:{} \ntemp_local:{}\ntemp_max:{}",line_mud_center,colum_mud_center,temp_local,temp_max);
    //

    while  temp_local > temp_max {
        if map[temp_local as usize][colum_mud_center as usize] != 1 {
            map[temp_local as usize ][colum_mud_center as usize] = 2;
            rende_frame(map);
        }
        rende_frame(map);
        temp_local -= 1;
    }
    map
}

fn bot_location(map: [[i32; LINE as usize]; COLUM as usize]) -> [i32;2]{
    let mut robot_location_x_y: [i32;2] = [0,0];
    for tmp_line in 0..LINE as usize{
        for tmp_colum in 0..COLUM as usize{
            if map [tmp_line][tmp_colum] == 1{
                robot_location_x_y[0] = tmp_line as i32;
                robot_location_x_y[1] = tmp_colum as i32;
                return robot_location_x_y;
            };
        }
        }
    robot_location_x_y
    /*
     *        let robot_location_x_y = bot_location(map);
     *    let line_robot = robot_location_x_y[0];
     *    let colum_robot = robot_location_x_y[1];
     *    let/* mut */temp_max;
     *
    */
}

fn lauch_bot(mut map: [[i32; LINE as usize]; COLUM as usize]) -> [[i32; LINE as usize]; COLUM as usize]{
    map [0][0] = 1;
    map
}

fn rende_frame (/* rende_mode: i32, */map: [[i32; LINE as usize]; COLUM as usize]){
    /*
    let local_line: i32 = LINE;
    let local_colum: i32 = COLUM;
    */
    println!("- - -");
    for tmp_line in 0..LINE as usize{
        for tmp_colum in 0..COLUM as usize{
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
