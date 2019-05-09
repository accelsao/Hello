
public class Main {
    public static void main(String[] args){
        SharedData data = new SharedData();
        Reader reader = new Reader(data);
        Writer writer = new Writer(data);

        for(int i=0;i<5;i++){
            Thread rd = new Thread(reader);
            rd.start();
        }
        for(int i=0;i<3;i++){
            Thread wt = new Thread(writer);
            wt.start();
        }

    }
}
