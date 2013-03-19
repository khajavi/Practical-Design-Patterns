interface Icecream {
	public String makeIcecream();
}

class SimpleIcecream implements Icecream {
	public String makeIcecream() {
		return "Base Icecream";
	}
}

abstract class IcecreamDecorator implements Icecream {
	protected Icecream specialIcecream;

	public IcecreamDecorator( Icecream specialIcecream ) {
		this.specialIcecream = specialIcecream;
	}
	
	public String makeIcecream() {
		return specialIcecream.makeIcecream();
	}
}

class NuttyDecorator extends IcecreamDecorator {
	public NuttyDecorator( Icecream specialIcecream ) {
		super( specialIcecream );
	}

	public String makeIcecream() {
		return specialIcecream.makeIcecream() + addNuts();
	}

	private String addNuts() {
		return " + cruncy nuts";
	}
}

class HoneyDecorator extends IcecreamDecorator {
	public HoneyDecorator( Icecream specialIcecream ) {
		super( specialIcecream );
	}

	public String makeIcecream() {
		return specialIcecream.makeIcecream() + addHoney();
	}

	private String addHoney() {
		return " + sweet honey";
	}
}

public class TestDecorator {
	public static void main(String args[]) {
		Icecream icecream = new HoneyDecorator( new NuttyDecorator( new SimpleIcecream() ) );
		System.out.println( icecream.makeIcecream() );
	}
}
