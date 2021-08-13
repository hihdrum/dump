use std::io;
use std::io::Read;

fn main() {

//    let mut i : i32 = 0;

    for byte in io::stdin().bytes() {
//        i = i + 1;
        print!("{:<02x} ", byte.unwrap());
    }

//    print!("\nDBG: i = {}", i);
}
