--3.1 INSERT
-- a Без указания списка полей
INSERT INTO client
VALUES 
	('Иван Иванович', 363636, 'bonuscard_1'),
	('Петр Сергеевич', 373686, 'bonuscard_2'),
	('Алена Ивановна', 367856, 'bonuscard_3');
INSERT INTO client
VALUES 
	('Валентин', 365436, 'bonuscard_1'),
	('Константин Иванович', 273606, 'bonuscard_2');
INSERT INTO equipment
VALUES 
	('10/10/2017', 'плойка', 2000),
	('07/08/2020', 'мойка', 10000),
	('02/11/2018', 'фен', 7000),
	('10/01/2019', 'плойка', 3000),
	('02/11/2018', 'фен', 4000),
	('02/04/2016', 'плойка', 6000);
INSERT INTO hairdresser
VALUES 
	('Алена Ивановна', 182838, 10000),
	('Алена Семеновна', 787008, 15000),
	('Екатерина Павловна', 767858, 11000);
--b. C указанием списка полей
INSERT INTO [service] (price, consumables, [time], [name])
VALUES 
	(3000, 'перчатки, воротничек, краска', 60, 'тонировка'),
	(3000, 'перчатки, воротничек, краска', 40, 'тонировка бледная'),
	(700, 'воротничек, спрей', 30, 'стрижка'),
	(1500, 'воротничек, спрей', 30, 'фигурная стрижка'),
    (3500, 'перчатки, воротничек, оксид, краска', 120, 'покраска'),
	(3000, 'перчатки, воротничек, оксид', 120, 'покраска со своей краской'),
	(3700, 'перчатки, воротничек, оксид, краска, резинки', 120, 'мелирование'),
	(4500, 'перчатки, воротничек, оксид, краска', 120, 'яркая покраска');
--c. С чтением значения из другой таблицы
INSERT INTO hairdresser_make_service
	(id_hairdresser, id_service) 
VALUES 
	((SELECT TOP 1  id_hairdresser FROM hairdresser WHERE full_name = 'Алена Ивановна'), (SELECT TOP 1  id_service FROM service WHERE [name] = 'тонировка')),
	((SELECT TOP 1  id_hairdresser FROM hairdresser WHERE full_name = 'Алена Ивановна'), (SELECT TOP 1  id_service FROM service WHERE [name] = 'стрижка')),
	((SELECT TOP 1  id_hairdresser FROM hairdresser WHERE full_name = 'Екатерина Павловна'), (SELECT TOP 1  id_service FROM service WHERE [name] = 'стрижка')),
	((SELECT TOP 1  id_hairdresser FROM hairdresser WHERE full_name = 'Алена Семеновна'), (SELECT TOP 1  id_service FROM service WHERE [name] = 'тонировка'));

INSERT INTO service_had_done
	(id_hairdresser, id_service, id_client, date_time) 
VALUES 
	((SELECT TOP 1  id_hairdresser FROM hairdresser WHERE full_name = 'Алена Ивановна'), (SELECT TOP 1 id_service FROM service WHERE [name] = 'стрижка'), 
	(SELECT TOP 1  id_client FROM client WHERE full_name = 'Валентин'), '17/01/2022'),
	((SELECT TOP 1  id_hairdresser FROM hairdresser WHERE full_name = 'Алена Ивановна'), (SELECT TOP 1  id_service FROM service WHERE [name] = 'тонировка'), 
	(SELECT TOP 1  id_client FROM client WHERE full_name = 'Алена Ивановна'), '17/01/2022'),
	((SELECT TOP 1  id_hairdresser FROM hairdresser WHERE full_name = 'Екатерина Павловна'), (SELECT TOP 1  id_service FROM service WHERE [name] = 'стрижка'), 
	(SELECT TOP 1  id_client FROM client WHERE full_name = 'Константин Иванович'), '21/02/2022'),
	((SELECT TOP 1  id_hairdresser FROM hairdresser WHERE full_name = 'Екатерина Павловна'), (SELECT TOP 1  id_service FROM service WHERE [name] = 'тонировка'), 
	(SELECT TOP 1  id_client FROM client WHERE full_name = 'Алена Ивановна'), '11/03/2022');

--3.2 DELETE
--a. Всех записей
TRUNCATE TABLE hairdresser_make_service;
TRUNCATE TABLE service_had_done;
--b. По условию
DELETE FROM hairdresser
WHERE  
	full_name = 'Алена Ивановна';

--3.3. UPDATE
--a. Всех записей
UPDATE [service] 
SET price = price*1.1;
--b. По условию обновляя один атрибут
UPDATE equipment
SET last_servise_date = '10/10/2021'  WHERE [type] = 'фен';
--c.По условию обновляя несколько атрибутов
UPDATE [service]
SET [time] = [time] + 20,
	price = price*1.2 
WHERE [time] > 60;

--3.4.SELECT
--a. С набором извлекаемых атрибутов (SELECT atr1, atr2 FROM...)
SELECT [type], price FROM equipment;
--b. Со всеми атрибутами (SELECT * FROM...)
SELECT * FROM client;
SELECT * FROM hairdresser;
SELECT * FROM equipment;
SELECT * FROM hairdresser_make_service;
SELECT * FROM [service];
--c. С условием по атрибуту (SELECT * FROM ... WHERE atr1 = value)
SELECT * FROM equipment 
WHERE price > 7000;

--3.5. SELECT ORDER BY + TOP (LIMIT)
--a. С сортировкой по возрастанию ASC + ограничение вывода количества записей
SELECT TOP 2 * 
FROM equipment 
ORDER BY last_servise_date ASC;
--b. С сортировкой по убыванию DESC
SELECT * 
FROM equipment 
ORDER BY last_servise_date DESC;
--c. С сортировкой по двум атрибутам + ограничение вывода количества записей
SELECT TOP 3 * 
FROM [service]
ORDER BY price ASC, [time] ASC;
--d. С сортировкой по первому атрибуту, из списка извлекаемых
SELECT full_name, phone_number
FROM client
ORDER BY 1 ASC;

--3.6. Работа с датами
--Необходимо, чтобы одна из таблиц содержала атрибут с типом DATETIME. Например,
--таблица авторов может содержать дату рождения автора.
--a. WHERE по дате
SELECT * 
FROM equipment 
WHERE last_servise_date < '01/01/2018';
--b. WHERE дата в диапазоне
SELECT * 
FROM equipment 
WHERE last_servise_date BETWEEN '01/01/2017' AND '01/01/2021';
--c. Извлечь из таблицы не всю дату, а только год. Например, год рождения автора.
SELECT YEAR((SELECT last_servise_date FROM equipment WHERE [type] = 'мойка'));

--3.7. Функции агрегации
--a. Посчитать количество записей в таблице
SELECT COUNT(*) FROM equipment;
--b. Посчитать количество уникальных записей в таблице
SELECT COUNT(DISTINCT [type]) FROM equipment;
--c. Вывести уникальные значения столбца
SELECT DISTINCT [type] FROM equipment;
--d. Найти максимальное значение столбца
SELECT MAX(price) FROM [service];
--e. Найти минимальное значение столбца
SELECT MIN(price) FROM [service];
--f. Написать запрос COUNT() + GROUP BY
SELECT price, COUNT(*) FROM [service]
GROUP BY 
	price;

--3.8. SELECT GROUP BY + HAVING
--a. Написать 3 разных запроса с использованием GROUP BY + HAVING. Для
--каждого запроса написать комментарий с пояснением, какую информацию
--извлекает запрос. Запрос должен быть осмысленным, т.е. находить информацию,
--которую можно использовать.

--Проверить, что оборудования хватает для трех парихмахером, не меньше одного предмета каждого типа каждому
SELECT [type]
FROM equipment
GROUP BY [type]
HAVING COUNT([type]) < 3;

--Были проблемы с бонусными картами, надо проверить что карты уникальны, найти неуникальные
SELECT bonus_card
FROM client 
GROUP BY bonus_card
HAVING COUNT(bonus_card) > 1;

--У парихмахера в запасе 50 минут, узнать, сколько существует различных процедур, которые можно успеть за это время 
SELECT [time], COUNT([time])
FROM [service]
GROUP BY [time]
HAVING [time] <= 50;

--3.9. SELECT JOIN
--a. LEFT JOIN двух таблиц и WHERE по одному из атрибутов
SELECT * FROM hairdresser h
LEFT JOIN service_had_done s ON s.id_hairdresser=h.id_hairdresser
WHERE date_time > '01/01/2022';
--b. RIGHT JOIN. Получить такую же выборку, как и в 3.9 a
SELECT * FROM  hairdresser h
RIGHT JOIN service_had_done s  ON s.id_hairdresser=h.id_hairdresser
WHERE date_time > '01/01/2022';
--c. LEFT JOIN трех таблиц + WHERE по атрибуту из каждой таблицы
SELECT * FROM hairdresser h
LEFT JOIN service_had_done m ON h.id_hairdresser=m.id_hairdresser
LEFT JOIN [service] s ON s.id_service = m.id_service
WHERE
	date_time > '01/01/2022'  AND
	full_name = 'Алена Ивановна' AND
	price < 3000;
--d. INNER JOIN двух таблиц
SELECT * FROM hairdresser h
INNER JOIN service_had_done s ON s.id_hairdresser=h.id_hairdresser;

--3.10. Подзапросы
--a. Написать запрос с условием WHERE IN (подзапрос)
SELECT * FROM service
WHERE 
	id_service in (SELECT id_service FROM service_had_done);
--b. Написать запрос SELECT atr1, atr2, (подзапрос) FROM ...
SELECT date_time, (SELECT [name] FROM [service] s WHERE s.id_service=d.id_service) FROM service_had_done d;
--c. Написать запрос вида SELECT * FROM (подзапрос)
SELECT * FROM (SELECT * FROM client) AS c;
--d. Написать запрос вида SELECT * FROM table JOIN (подзапрос) ON …
SELECT * FROM  hairdresser h
LEFT JOIN (SELECT * FROM hairdresser_make_service) m ON h.id_hairdresser = m.id_hairdresser
WHERE 
	full_name != 'Алена Ивановна';