# 🧠 Minitalk Project

> Un projet de communication inter-processus via signaux Unix.

## 📦 Contenu

- `server`: Reçoit les signaux et affiche le message.
- `client`: Envoie un message bit par bit.

## 🚀 Compilation

```bash
make
./server
./client <PID> "Hello World"

Exemple d'exécution

$ ./server
the pid of server is 4242

$ ./client 4242 "42 est génial !"
42 est génial !

🛠 Fonctions principales

    kill() — envoi de signaux

    sigaction() — gestion avancée des signaux

    pause() — attendre un signal

🧪 Testé sous

    🐧 Linux (Ubuntu 22.04)

    ✅ Comportement attendu


