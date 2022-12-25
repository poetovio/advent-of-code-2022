use std::fs;

fn main() {

    let input = fs::read_to_string("input.txt")
        .expect("Failed to read input file");

    let mut stevec = 0;
    let mut vec: Vec<i32> = Vec::new();

    let v: Vec<&str> = input.lines().collect();

    let mut st_kalorij = 0;


    for value in v.iter() {
        if value.is_empty() {
            if st_kalorij > stevec {
                stevec = st_kalorij;
            }

            vec.push(st_kalorij);

            st_kalorij = 0;
        } else {
            st_kalorij += value.parse::<i32>().unwrap();
        }
    }

    vec.sort();
    vec.reverse();

    println!("Part 1 -> {stevec}");
    println!("Part 2 -> {}", vec[0] + vec[1] + vec[2]);
}