package fila;

public class Fila {

	public static void main(String[] args) {
		Cliente pessoa1 = new Cliente("Francisco", 10);
		Cliente pessoa2 = new Cliente("Marcos", 29);
		Cliente pessoa3 = new Cliente("Anderson", 70);
		Cliente pessoa4 = new Cliente("José", 80);

		Fila_Cliente fila = new Fila_Cliente();

		fila.add(pessoa1);
		fila.add(pessoa2);
		fila.add(pessoa3);
		fila.add(pessoa4);

		fila.show();

		System.out.println("------------------------------------");

		fila.remover();
		fila.show();
	}

}
