export class Carro {
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