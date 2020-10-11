package pilha;

public class People {

	public static void main(String[] args) {
		Stack pilha = new Stack();

		pilha.push("Jair");
		pilha.push("Francisco");
		pilha.push("Oliveira");

		System.out.println("Nome: " + pilha.topoShow());
		pilha.pop();
		System.out.println("Nome: " + pilha.topoShow());
		pilha.pop();
		pilha.pop();
		// System.out.println("Nome: " + pilha.topoShow());
	}

}
