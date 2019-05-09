import java.util.concurrent.Semaphore;

public class SharedData {
    Semaphore mutex = new Semaphore(1); // reader申請讀入
    Semaphore writelock = new Semaphore(1); // wrtier 寫的時候申請勿擾
    Semaphore to_write = new Semaphore(1); // writer 出現後申請寫入
    int readcount=0;
}
