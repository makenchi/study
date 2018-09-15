class Carro {
    private modelo: string
    private numDePortas: number
    private velocidade: number = 0

    constructor(modelo: string, numDePortas: number){
        this.modelo = modelo
        this.numDePortas = numDePortas
    }

    public acelerar(): void{
        this.velocidade = this.velocidade + 10
    }

    public parar(): void{
        this.velocidade = 0
    }

    public mostraVelocidade(): number{
        return this.velocidade
    }
}

class Consesionaria{
    private endereco: string
    private listaDeCarros: any

    constructor(endereco: string){        
        this.endereco = endereco
    }

    public fornecerEndereco(): string{
        return this.endereco
    }

    public mostrarListaDeCarros(): any{
        return this.listaDeCarros
    }
}

class Pessoa{
    private nome: string
    private carroPreferido: string
    private carro: any

    constructor(nomePessoa: string, carroP: string){
        this.nome = nomePessoa
        this.carroPreferido = carroP
    }

    public dizerNome(): string{
        return this.nome
    }

    public dizerCarroPreferido(): string{
        return this.carro
    }

    public comprarCarro(carroComprado: any): void{
        this.carro = carroComprado
    }

    public dizerCarroQueTem(): any{
        return this.carro
    }
}