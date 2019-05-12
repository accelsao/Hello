public class Writer implements Runnable {
    SharedData data;
    boolean running = true;


    public Writer(SharedData data) {
        super();
        this.data = data;
        this.running = true;
    }

    @Override
    public void run() {
        while(Thread.currentThread().isInterrupted() == false){



            try {
                Thread.sleep((1000));
            } catch (InterruptedException e) {

                Thread.currentThread().interrupt();
            }
            try{
                data.to_write.acquire(); // wrtier 申請 不讓新reader在進來
                data.writelock.acquire();
                // write

                System.out.printf("[%s] enter context switch.\n", Thread.currentThread().getName());
                // Write random numbers
                int num = data.rnd.nextInt(100);
                data.data_bs.add(num);
                System.out.printf("[%s] writes %d in data_bs.\n", Thread.currentThread().getName(), num);
                //System.out.printf("[Writer%d] writes %d in data_bs.\n", Thread.currentThread().getId(), num);
                System.out.printf("[%s] sleep for 5s.\n", Thread.currentThread().getName());
                //System.out.printf("[Writer%d] sleep for 5s", Thread.currentThread().getId());
                for (int i=0;i<5;i++){
                    Thread.sleep(1000);
                    System.out.print(". ");
                }

                System.out.printf("[%s] Wake Up!!!.\n", Thread.currentThread().getName());
                //System.out.printf("[Writer%d] Wake Up!!.\n", Thread.currentThread().getId());
                System.out.printf("[%s] exit context switch.\n", Thread.currentThread().getName());
                //System.out.printf("[Writer%d] exit cs.\n", Thread.currentThread().getId());
                data.writers_cnt += 1;
                // write
                data.writelock.release();
                data.to_write.release();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }



        }

    }
}
