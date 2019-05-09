public class Writer implements Runnable {
    SharedData data;

    public Writer(SharedData data) {
        super();
        this.data = data;
    }

    @Override
    public void run() {
        while(true){
            try{
                data.to_write.acquire(); // wrtier 申請 不讓新reader在進來
                data.writelock.acquire();
                // write
                System.out.printf("[Writer%d] enter cs.\n", Thread.currentThread().getId());
                System.out.printf("[Writer%d] is WRITING.\n", Thread.currentThread().getId());
                System.out.printf("[Writer%d] sleep for 5s. . . . . .", Thread.currentThread().getId());
                Thread.sleep(5000);
                System.out.printf("[Writer%d] Wake Up!!.\n", Thread.currentThread().getId());
                System.out.printf("[Writer%d] exit cs.\n", Thread.currentThread().getId());
                // write
                data.writelock.release();
                data.to_write.release();
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
