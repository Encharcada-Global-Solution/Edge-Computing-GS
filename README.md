---

# 💧 Projeto: Monitoramento de Nível de Água com Arduino

## 🧠 Descrição do Problema

Em áreas urbanas e rurais, o monitoramento do nível de água é essencial para evitar enchentes, detectar transbordamentos em reservatórios ou simplesmente acompanhar o consumo. Em situações críticas, é necessário um sistema simples, barato e eficiente que alerte sobre níveis elevados de água de forma visual e sonora.

## 🎯 Visão Geral da Solução

Este projeto simula o monitoramento do nível de água usando um **potenciômetro** (representando o sensor de nível), um **display LCD** para exibir a porcentagem do reservatório, um **buzzer** para alertas sonoros, e **3 LEDs** para indicação visual (verde, amarelo e vermelho).

---

## ⚙️ Componentes Utilizados

| Componente           | Quantidade |
| -------------------- | ---------- |
| Arduino UNO          | 1          |
| Potenciômetro        | 1          |
| Display LCD 16x2     | 1          |
| Buzzer (ativo)       | 1          |
| LED Verde            | 1          |
| LED Amarelo          | 1          |
| LED Vermelho         | 1          |

---

## 🛠️ Como Funciona

* O **potenciômetro** simula o sensor de nível d'água.
* O valor é convertido em uma **porcentagem de 0% a 100%**.
* O **LCD** mostra essa porcentagem em tempo real.
* Os **LEDs** indicam visualmente o nível:

  * 🟢 Verde: até 74% (nível seguro)
  * 🟡 Amarelo: 75% a 89% (atenção)
  * 🔴 Vermelho: 90% a 100% (risco de transbordamento)
* O **buzzer** apita a partir de 75%:

  * Apito com intervalo (tipo sonar) que acelera conforme a água sobe.
  * Apito contínuo ao atingir 100%.

---

## 📸 Ilustração do Projeto

![image](https://github.com/user-attachments/assets/53350c78-3f2d-40b8-a87f-ee0dd6028950)

---

## 🚀 Instruções para Executar

1. Carregue o código no Arduino.
2. Gire o potenciômetro para simular a subida do nível da água.
3. Observe as mudanças no LCD, LEDs e buzzer.

---

## 🧪 Aplicações Futuras

* Substituir o potenciômetro por sensor de nível real (ultrassônico ou de boia).
* Conectar com rede IoT para envio de alertas via internet.
* Alimentação com bateria e energia solar para áreas externas.
