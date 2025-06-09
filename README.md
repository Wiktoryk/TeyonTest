Prosta Gra Wyścigowa  
**Test rekrutacyjny — Unreal Engine 5.5.4 + C++**

---

## Opis projektu

Projekt jest prostą grą wyścigową 3D, umożliwiającą:

- sterowanie samochodem w trybie arcade (własna implementacja ruchu),
- przejazd po prostej trasie,
- pomiar czasu przejazdu okrążenia,
- rejestrowanie liczby ukończonych okrążeń,
- zakończenie wyścigu po określonej liczbie okrążeń.

---

## Wymagania techniczne

- Unreal Engine **5.5.4**

---

## Sterowanie

| Akcja          | Klawisz / Pad |
|----------------|---------------|
| Przyspieszanie | W / Lewa gałka w górę |
| Hamowanie      | S / Lewa gałka w dół |
| Skręt w lewo   | A / Lewa gałka w lewo |
| Skręt w prawo  | D / Lewa gałka w prawo |
| Hamulec        | Lewy shift / Lewy bumper |
| Hamulec ręczny | Spacja / Lewy trigger |

---

## Struktura kodu

- `ARaceCarPawn` — klasa reprezentująca pojazd gracza
  - implementacja własnego ruchu pojazdu
  - system wykrywania podłoża
  - sprawdzanie poprawności przejazdu
- `ARaceGameMode` — tryb gry
  - zarządzanie ilością okrążeń
  - zakończenie wyścigu
- `ULapTimerComponent` — komponent pomiaru czasu okrążeń
- `ALapTrigger` / `ACheckpointTrigger` — system detekcji poprawnego okrążenia
- `ARaceHUD` - HUD gry

---

## Funkcjonalności

✅ własny model sterowania pojazdem (przyspieszenie, hamowanie, ręczny, skręt)  
✅ kamera podążająca za pojazdem  
✅ system czasu okrążenia  
✅ system końca wyścigu  
✅ zabezpieczenie przed sztucznym nabijaniem okrążeń przez cofanie

---

## Budowanie

1. Pobierz repozytorium
2. Otwórz plik `.uproject` w **Unreal Engine 5.5.4**
3. Skopiluj kod
4. Zbuduj projekt

---

## Uwagi

- System kolizji podłoża oparty jest o Physical Materials — pozwala wykrywać nawierzchnię (np. asfalt / trawa).
- W wyniku kuriozalnego błędu, pewne pliki nie były uwzględnianie w projekcie, co uniemożliwiło poprawne zaimplementowanie UI i checkpointów (czasy przejazdu są w logach)
- Wykrywanie podłoża po prostu nie działa, zarówno dla wykrywania trzymania się trasy jak i grawitacji (włączenie grawitacji spowoduje wypadnięcie pojazdu pod mapę)

---

## Licencja

Projekt stworzony na potrzeby testu rekrutacyjnego.  
Copyright (c) 2025 by Wiktor Oliwa.

