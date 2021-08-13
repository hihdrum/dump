use std::io;
use std::io::Read;

fn main() {
    for byte in io::stdin().bytes() {
        print!("{:<02x} ", byte.unwrap());
    }
}
