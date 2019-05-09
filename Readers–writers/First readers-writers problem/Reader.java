import java.util.Random;

public class Reader implements Runnable{

    SharedData data;

    public Reader(SharedData data) {
        super();
        this.data = data;
    }


    @Override
    public void run() {
        while (true){
            try{
                //data.readerlimit.acquire();
                data.to_write.acquire(); // 有wrtier申請的時候, 就無法讀入新的
                data.mutex.acquire(); // modify count lock
                data.readcount++;
                if(data.readcount == 1){ // lock writer
                    data.writelock.acquire();
                }
                data.mutex.release();
                data.to_write.release();
                // read
                System.out.printf("[Reader%d] enter cs.\n", Thread.currentThread().getId());
                System.out.printf("[Reader%d] is READING.\n", Thread.currentThread().getId());
                Random rnd = new Random();
                int time = (rnd.nextInt(3)+1) * 1000;
                System.out.printf("[Reader%d] sleep for %dms.\n", Thread.currentThread().getId(), time);
                Thread.sleep(time);
                System.out.printf("[Reader%d] exit cs.\n", Thread.currentThread().getId());
                // read

                data.mutex.acquire(); // lock reader
                data.readcount--;
                if(data.readcount == 0){
                    data.writelock.release(); // unlock writer
                }
                data.mutex.release(); // unlock reader
                //data.readerlimit.release();

            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            try {
                Thread.sleep((1000));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }


        }
    }
}
