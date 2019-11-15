import java.util.Random;

public class Reader implements Runnable{

    SharedData data;
    boolean running = true;

    public Reader(SharedData data) {
        super();
        this.data = data;
        this.running = true;
    }


    @Override
    public void run() {
        while (Thread.currentThread().isInterrupted() == false){


            try {
                Thread.sleep((1000));
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
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
                System.out.printf("[%s] enter context switch.\n", Thread.currentThread().getName());
                //System.out.printf("[Reader%d] enter cs.\n", Thread.currentThread().getId());
                //System.out.printf("[Reader%d] is READING.\n", Thread.currentThread().getId());
                //System.out.printf("data_bs size %d\n", data.data_bs.size());

                if(data.data_bs.size() <= 0){
                    System.out.printf("[%s] reads Nothings.\n", Thread.currentThread().getName());
                }
                else{
                    int idx = data.rnd.nextInt(data.data_bs.size() );
                    int get_number = data.data_bs.get(idx);
                    System.out.printf("[%s] reads %d.\n", Thread.currentThread().getName(),  get_number);
                }


                int time = (data.rnd.nextInt(3)+1)*1000;
                System.out.printf("[%s] sleep for %dms.\n", Thread.currentThread().getName(), time);
                Thread.sleep(time);
                System.out.printf("[%s] exit context switch.\n", Thread.currentThread().getName());
                data.readers_cnt += 1;
                // read

                data.mutex.acquire(); // lock reader
                data.readcount--;
                if(data.readcount == 0){
                    data.writelock.release(); // unlock writer
                }
                data.mutex.release(); // unlock reader


            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}
