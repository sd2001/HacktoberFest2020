package fila;

public class No {
	private Cliente pessoa;
	private No prox;
	private No anterior;

	public Cliente getPessoa() {
		return pessoa;
	}

	public void setPessoa(Cliente pessoa) {
		this.pessoa = pessoa;
	}

	public No getProx() {
		return prox;
	}

	public void setProx(No prox) {
		this.prox = prox;
	}

	public No getAnterior() {
		return anterior;
	}

	public void setAnterior(No anterior) {
		this.anterior = anterior;
	}

}
