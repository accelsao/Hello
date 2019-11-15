import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws InterruptedException {


        Scanner input = new Scanner(System.in); // number of Readers
        System.out.print("Input Number of Readers: ");
        int r_num = input.nextInt(); // number of Readers
        System.out.print("Input Number of Writers: ");
        int w_num = input.nextInt(); // number of Writers

        SharedData data = new SharedData();
        Reader reader = new Reader(data);
        Writer writer = new Writer(data);

        Thread rd[] = new Thread[r_num];
        Thread wt[] = new Thread[w_num];

        for(int i=0;i<r_num;i++){
            rd[i] = new Thread(reader);
            rd[i].setName(String.format("Reader #%d", i+1));
            rd[i].start();
        }
        for(int i=0;i<w_num;i++){
            wt[i] = new Thread(writer);
            wt[i].setName(String.format("Wrtier #%d", i+1));
            wt[i].start();
        }

        Thread.sleep(10000);//30s
        // INTERRUPT
        for(int i=0;i<r_num;i++){
            rd[i].interrupt();
        }
        for(int i=0;i<w_num;i++){
            wt[i].interrupt();
        }
        System.out.println("Program is Interrupted");
        System.out.print("Readers total: ");
        System.out.println(data.readers_cnt);
        System.out.print("Writers total: ");
        System.out.println(data.writers_cnt);
    }
}
