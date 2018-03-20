package bank;

public class CustomerBorrow extends Customer{
	int bm=0;//borrow
	CustomerBorrow() {
		
	}
	CustomerBorrow(String name){
		super.customer_name=name;
	}
	public void takemoney(int money) {
		super.money=super.money-money;
		show();
	}
	public void savemoney(int money) {
		super.money=super.money+money;
		show();
	}
	public void borrow(int a) {
		this.bm+=a;
		super.money=super.money-a;
		show();
	}
	public void choose(int mode,int number) {//交換更正
		if(mode==1)show();
		else if(mode==2) {
			int dol=input.nextInt();
			savemoney(dol);
		}
		else if(mode==3) {
			int dol=input.nextInt();
			takemoney(dol);
		}
		else if(mode==5) {
			int dol=input.nextInt();
			if(dol>money) {
				borrow(dol);
			}
			else System.out.println("You don't need to borrow money!!!");
		}
		else if((mode==4||mode>5)&&number==3) {
			error();
		}
	}
	public void show() {
		System.out.println(super.customer_name+" have "+super.money+" in the bank ");
		System.out.println(super.customer_name+" borrow "+this.bm);
	}
}
