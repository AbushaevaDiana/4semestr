--3.1 INSERT
-- a ��� �������� ������ �����
INSERT INTO client
VALUES 
	('���� ��������', 363636, 'bonuscard_1'),
	('���� ���������', 373686, 'bonuscard_2'),
	('����� ��������', 367856, 'bonuscard_3');
INSERT INTO client
VALUES 
	('��������', 365436, 'bonuscard_1'),
	('���������� ��������', 273606, 'bonuscard_2');
INSERT INTO equipment
VALUES 
	('10/10/2017', '������', 2000),
	('07/08/2020', '�����', 10000),
	('02/11/2018', '���', 7000),
	('10/01/2019', '������', 3000),
	('02/11/2018', '���', 4000),
	('02/04/2016', '������', 6000);
INSERT INTO hairdresser
VALUES 
	('����� ��������', 182838, 10000),
	('����� ���������', 787008, 15000),
	('��������� ��������', 767858, 11000);
--b. C ��������� ������ �����
INSERT INTO [service] (price, consumables, [time], [name])
VALUES 
	(3000, '��������, ����������, ������', 60, '���������'),
	(3000, '��������, ����������, ������', 40, '��������� �������'),
	(700, '����������, �����', 30, '�������'),
	(1500, '����������, �����', 30, '�������� �������'),
    (3500, '��������, ����������, �����, ������', 120, '��������'),
	(3000, '��������, ����������, �����', 120, '�������� �� ����� �������'),
	(3700, '��������, ����������, �����, ������, �������', 120, '�����������'),
	(4500, '��������, ����������, �����, ������', 120, '����� ��������');
--c. � ������� �������� �� ������ �������
INSERT INTO hairdresser_make_service
	(id_hairdresser, id_service) 
VALUES 
	((SELECT TOP 1  id_hairdresser FROM hairdresser WHERE full_name = '����� ��������'), (SELECT TOP 1  id_service FROM service WHERE [name] = '���������')),
	((SELECT TOP 1  id_hairdresser FROM hairdresser WHERE full_name = '����� ��������'), (SELECT TOP 1  id_service FROM service WHERE [name] = '�������')),
	((SELECT TOP 1  id_hairdresser FROM hairdresser WHERE full_name = '��������� ��������'), (SELECT TOP 1  id_service FROM service WHERE [name] = '�������')),
	((SELECT TOP 1  id_hairdresser FROM hairdresser WHERE full_name = '����� ���������'), (SELECT TOP 1  id_service FROM service WHERE [name] = '���������'));

INSERT INTO service_had_done
	(id_hairdresser, id_service, id_client, date_time) 
VALUES 
	((SELECT TOP 1  id_hairdresser FROM hairdresser WHERE full_name = '����� ��������'), (SELECT TOP 1 id_service FROM service WHERE [name] = '�������'), 
	(SELECT TOP 1  id_client FROM client WHERE full_name = '��������'), '17/01/2022'),
	((SELECT TOP 1  id_hairdresser FROM hairdresser WHERE full_name = '����� ��������'), (SELECT TOP 1  id_service FROM service WHERE [name] = '���������'), 
	(SELECT TOP 1  id_client FROM client WHERE full_name = '����� ��������'), '17/01/2022'),
	((SELECT TOP 1  id_hairdresser FROM hairdresser WHERE full_name = '��������� ��������'), (SELECT TOP 1  id_service FROM service WHERE [name] = '�������'), 
	(SELECT TOP 1  id_client FROM client WHERE full_name = '���������� ��������'), '21/02/2022'),
	((SELECT TOP 1  id_hairdresser FROM hairdresser WHERE full_name = '��������� ��������'), (SELECT TOP 1  id_service FROM service WHERE [name] = '���������'), 
	(SELECT TOP 1  id_client FROM client WHERE full_name = '����� ��������'), '11/03/2022');

--3.2 DELETE
--a. ���� �������
TRUNCATE TABLE hairdresser_make_service;
TRUNCATE TABLE service_had_done;
--b. �� �������
DELETE FROM hairdresser
WHERE  
	full_name = '����� ��������';

--3.3. UPDATE
--a. ���� �������
UPDATE [service] 
SET price = price*1.1;
--b. �� ������� �������� ���� �������
UPDATE equipment
SET last_servise_date = '10/10/2021'  WHERE [type] = '���';
--c.�� ������� �������� ��������� ���������
UPDATE [service]
SET [time] = [time] + 20,
	price = price*1.2 
WHERE [time] > 60;

--3.4.SELECT
--a. � ������� ����������� ��������� (SELECT atr1, atr2 FROM...)
SELECT [type], price FROM equipment;
--b. �� ����� ���������� (SELECT * FROM...)
SELECT * FROM client;
SELECT * FROM hairdresser;
SELECT * FROM equipment;
SELECT * FROM hairdresser_make_service;
SELECT * FROM [service];
--c. � �������� �� �������� (SELECT * FROM ... WHERE atr1 = value)
SELECT * FROM equipment 
WHERE price > 7000;

--3.5. SELECT ORDER BY + TOP (LIMIT)
--a. � ����������� �� ����������� ASC + ����������� ������ ���������� �������
SELECT TOP 2 * 
FROM equipment 
ORDER BY last_servise_date ASC;
--b. � ����������� �� �������� DESC
SELECT * 
FROM equipment 
ORDER BY last_servise_date DESC;
--c. � ����������� �� ���� ��������� + ����������� ������ ���������� �������
SELECT TOP 3 * 
FROM [service]
ORDER BY price ASC, [time] ASC;
--d. � ����������� �� ������� ��������, �� ������ �����������
SELECT full_name, phone_number
FROM client
ORDER BY 1 ASC;

--3.6. ������ � ������
--����������, ����� ���� �� ������ ��������� ������� � ����� DATETIME. ��������,
--������� ������� ����� ��������� ���� �������� ������.
--a. WHERE �� ����
SELECT * 
FROM equipment 
WHERE last_servise_date < '01/01/2018';
--b. WHERE ���� � ���������
SELECT * 
FROM equipment 
WHERE last_servise_date BETWEEN '01/01/2017' AND '01/01/2021';
--c. ������� �� ������� �� ��� ����, � ������ ���. ��������, ��� �������� ������.
SELECT YEAR((SELECT last_servise_date FROM equipment WHERE [type] = '�����'));

--3.7. ������� ���������
--a. ��������� ���������� ������� � �������
SELECT COUNT(*) FROM equipment;
--b. ��������� ���������� ���������� ������� � �������
SELECT COUNT(DISTINCT [type]) FROM equipment;
--c. ������� ���������� �������� �������
SELECT DISTINCT [type] FROM equipment;
--d. ����� ������������ �������� �������
SELECT MAX(price) FROM [service];
--e. ����� ����������� �������� �������
SELECT MIN(price) FROM [service];
--f. �������� ������ COUNT() + GROUP BY
SELECT price, COUNT(*) FROM [service]
GROUP BY 
	price;

--3.8. SELECT GROUP BY + HAVING
--a. �������� 3 ������ ������� � �������������� GROUP BY + HAVING. ���
--������� ������� �������� ����������� � ����������, ����� ����������
--��������� ������. ������ ������ ���� �����������, �.�. �������� ����������,
--������� ����� ������������.

--���������, ��� ������������ ������� ��� ���� ������������, �� ������ ������ �������� ������� ���� �������
SELECT [type]
FROM equipment
GROUP BY [type]
HAVING COUNT([type]) < 3;

--���� �������� � ��������� �������, ���� ��������� ��� ����� ���������, ����� ������������
SELECT bonus_card
FROM client 
GROUP BY bonus_card
HAVING COUNT(bonus_card) > 1;

--� ����������� � ������ 50 �����, ������, ������� ���������� ��������� ��������, ������� ����� ������ �� ��� ����� 
SELECT [time], COUNT([time])
FROM [service]
GROUP BY [time]
HAVING [time] <= 50;

--3.9. SELECT JOIN
--a. LEFT JOIN ���� ������ � WHERE �� ������ �� ���������
SELECT * FROM hairdresser h
LEFT JOIN service_had_done s ON s.id_hairdresser=h.id_hairdresser
WHERE date_time > '01/01/2022';
--b. RIGHT JOIN. �������� ����� �� �������, ��� � � 3.9 a
SELECT * FROM  hairdresser h
RIGHT JOIN service_had_done s  ON s.id_hairdresser=h.id_hairdresser
WHERE date_time > '01/01/2022';
--c. LEFT JOIN ���� ������ + WHERE �� �������� �� ������ �������
SELECT * FROM hairdresser h
LEFT JOIN service_had_done m ON h.id_hairdresser=m.id_hairdresser
LEFT JOIN [service] s ON s.id_service = m.id_service
WHERE
	date_time > '01/01/2022'  AND
	full_name = '����� ��������' AND
	price < 3000;
--d. INNER JOIN ���� ������
SELECT * FROM hairdresser h
INNER JOIN service_had_done s ON s.id_hairdresser=h.id_hairdresser;

--3.10. ����������
--a. �������� ������ � �������� WHERE IN (���������)
SELECT * FROM service
WHERE 
	id_service in (SELECT id_service FROM service_had_done);
--b. �������� ������ SELECT atr1, atr2, (���������) FROM ...
SELECT date_time, (SELECT [name] FROM [service] s WHERE s.id_service=d.id_service) FROM service_had_done d;
--c. �������� ������ ���� SELECT * FROM (���������)
SELECT * FROM (SELECT * FROM client) AS c;
--d. �������� ������ ���� SELECT * FROM table JOIN (���������) ON �
SELECT * FROM  hairdresser h
LEFT JOIN (SELECT * FROM hairdresser_make_service) m ON h.id_hairdresser = m.id_hairdresser
WHERE 
	full_name != '����� ��������';