import java.io.*;

class Dump {
  public static void main(String args[]) {

    try {
      while(true) {
        int ch = System.in.read();
        if(-1 == ch) {
          break;
        }

        System.out.printf("%02x ", ch);
      }
    } catch (IOException e) {
      System.out.println("Error reading from user");
    }

  }
}
