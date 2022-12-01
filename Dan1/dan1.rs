use std::env;
use std::fs;
use std::fmt::Display;


fn main() {

    let vsebina = fs::read_to_string("input2.txt")
        .expect("Lahko preberem file");

    let mut stevec = 0;
    let mut vmesnaVrednost = 0;

    let v: Vec<&str> = vsebina.lines().collect();

    for value in v.iter().enumerate() {
        if (value.is_empty()) {
            if (vmesnaVrednost > stevec) {
                stevec = vmesnaVrednost;
            }
            vmesnaVrednost = 0;
        } else {
            vmesnaVrednost = value.parse();
            println!("{}", vmesnaVrednost);
        }
    }

}