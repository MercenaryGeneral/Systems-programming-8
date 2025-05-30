# myRPC: Remote Procedure Call System
**Система удалённого выполнения команд через сокеты с авторизацией пользователей**

## Назначение
Система позволяет:
- Выполнять Bash-команды на удалённом сервере;
- Контролировать доступ через конфигурационные файлы;
- Логировать операции через `libmysyslog`;
- Поддерживает текстовый.

## Установка
### Из deb-пакетов:
#### На сервере
```bash
sudo apt install ./deb/myrpc-server_1.0-1_amd64.deb
```
#### На клиенте
```bash
sudo apt install ./deb/myrpc-client_1.0-1_amd64.deb
```
### Установка deb-пакета libmysyslog
```bash
sudo apt install ./deb/libmysyslog_1.0-1_amd64.deb
```
## Запуск сервера:
```bash
sudo myrpc-server
```
## Пример вызова команды с клиента:
```bash
./myrpc-client -h 127.0.0.1 -p 1234 -s -c "ls -la"
./myrpc-client -h 127.0.0.1 -p 1234 -d -c "ls -la"
```

