package com.example.alunos.imc;

public class Imc {

    private int peso;
    private double altura;

    public Imc(int peso, double altura){
        this.peso = peso;
        this.altura = altura;
    }

    public double calcularValor() {
        if (peso > 0 && altura > 0) {
            return (peso / ((altura/100) * (altura/100)));
        } else {
            return 0;
        }
    }

    public String calcularCategoria(){
        double imc = calcularValor();
        if (imc > 0 && imc < 18.5) {
             return "BAIXO PESO";
        }else if (imc >= 18.5 && imc < 25){
            return "ADEQUADO";
        } else if (imc >= 25 && imc < 30){
            return "SOBREPESO";
        } else if (imc >= 30) {
            return "OBESIDADE";
        }
        else {
            return  "Dados Inválidos";
        }
    }

    public String descricao(){
        double imc = calcularValor();
        if (imc > 0 && imc < 18.5) {
            return "Seu peso está abaixo do recomendado para sua altura, é recomendável a procura de um Nutricionaista para ganho de peso.";
        }else if (imc >= 18.5 && imc < 25){
            return "Seu peso está adequado ao recomendado para sua altura.";
        } else if (imc >= 25 && imc < 30){
            return "Seu peso indica um estado de Pré-Obesidade, é recomendável a procura de um Nutricionista para ajuste de peso.";
        } else if (imc >= 30) {
            return "Seu peso indica um estado de Obesidade, é recomendável a procura de um Nutricionista para perda de peso.";
        }
        else {
            return  "";
        }
    }
}
