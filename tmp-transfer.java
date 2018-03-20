package bank;

public class CustomerTransfer extends Customer{
	int tm=0;//transfer money
	public CustomerTransfer(){
		
	}
	CustomerTransfer(String name){
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
	public void transfer(int a) {
		this.tm+=a;
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
		else if(mode==4) {
			int dol=input.nextInt();
			if(dol<=money) {
				transfer(dol);
			}
			else System.out.println("You don't have enough money!!!");
		}
		else if(mode>4&&number==2) {
			error();
		}
	}
	public void show() {
		System.out.println(super.customer_name+" have "+super.money+" in the bank ");
		System.out.println(super.customer_name+" transfer "+this.tm);
	}
	
}
