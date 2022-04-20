USE booking

-- 1. Добавить внешние ключи
ALTER TABLE booking
  ADD CONSTRAINT FK_booking_client
  FOREIGN KEY (id_client) REFERENCES client (id_client);
ALTER TABLE room_in_booking
  ADD CONSTRAINT FK_room_in_booking_booking 
  FOREIGN KEY (id_booking) REFERENCES booking (id_booking);
ALTER TABLE room_in_booking
  ADD CONSTRAINT FK_room_in_booking_room 
  FOREIGN KEY (id_room) REFERENCES room (id_room);
ALTER TABLE room
  ADD CONSTRAINT FK_room_hotel
  FOREIGN KEY (id_hotel) REFERENCES hotel (id_hotel);
ALTER TABLE room
  ADD CONSTRAINT FK_room_room_category
  FOREIGN KEY (id_room_category) REFERENCES room_category (id_room_category);

/*2. Выдать информацию о клиентах гостиницы “Космос”, проживающих в номерах
 категории “Люкс” на 1 апреля 2019г.*/
SELECT client.[name], client.phone  
	FROM client
INNER JOIN booking 
	ON booking.id_client = client.id_client 
INNER JOIN room_in_booking 
	ON room_in_booking.id_booking = booking.id_booking 
INNER JOIN room 
	ON room.id_room = room_in_booking.id_room
INNER JOIN room_category
	ON room_category.id_room_category = room.id_room_category
INNER JOIN hotel
	ON room.id_hotel = hotel.id_hotel  
	WHERE 
	    room_category.[name] = 'Люкс'
		AND checkin_date <= '2019-04-01'
		AND checkout_date > '2019-04-01'
		AND hotel.[name] = 'Космос';

/* 3. Дать список свободных номеров всех гостиниц на 22 апреля.*/
SELECT * 
FROM room
WHERE room.id_room NOT IN
	(SELECT room.id_room     
	FROM room
	INNER JOIN hotel
		ON room.id_hotel = hotel.id_hotel
	INNER JOIN room_in_booking
		ON room.id_room = room_in_booking.id_room
        WHERE 
		    checkin_date <= '2019-04-22'
			AND checkout_date > '2019-04-22');

--4. Дать количество проживающих в гостинице “Космос” на 23 марта по каждой категории номеров
SELECT room_category.[name], number_of_residents
FROM room_category
INNER JOIN
	(SELECT room_category.id_room_category , COUNT(*) AS 'number_of_residents'
	FROM room_category
	INNER JOIN room
		ON room_category.id_room_category = room.id_room_category
	INNER JOIN hotel 
		ON hotel.id_hotel = room.id_hotel
	INNER JOIN room_in_booking
		ON room.id_room = room_in_booking.id_room
	WHERE (room_in_booking.checkin_date <= '2019-03-23'
		AND room_in_booking.checkout_date > '2019-03-23' 
    AND hotel.[name] = 'Космос')
	GROUP BY room_category.id_room_category) AS t
ON room_category.id_room_category = t.id_room_category;

/* 5. Дать список последних проживавших клиентов по всем комнатам гостиницы
 “Космос”, выехавшим в апреле с указанием даты выезда. */
SELECT DISTINCT room_in_booking.id_room, room_in_booking.checkout_date, client.[name] FROM [room_in_booking]
INNER JOIN [booking] 
	ON booking.id_booking = room_in_booking.id_booking
INNER JOIN [client] 
	ON client.id_client = booking.id_booking
INNER JOIN 
   (SELECT MAX(room_in_booking.checkout_date) checkout_date, room_in_booking.id_room FROM [room_in_booking]
	INNER JOIN [booking] 
		ON booking.id_booking = room_in_booking.id_booking
	INNER JOIN [client] 
		ON client.id_client = booking.id_booking
	WHERE room_in_booking.checkin_date >= '2019-04-01' 
		AND room_in_booking.checkout_date < '2019-05-01'
	GROUP BY room_in_booking.id_room) t 
	ON t.checkout_date = room_in_booking.checkout_date AND room_in_booking.id_room = t.id_room
	ORDER BY room_in_booking.id_room ASC, client.[name]
	

 /* 6. Продлить на 2 дня дату проживания в гостинице “Космос” всем клиентам
 комнат категории “Бизнес”, которые заселились 10 мая.*/
 SELECT client.[name], client.phone, room_in_booking.checkout_date, room_in_booking.checkin_date FROM [client]
INNER JOIN [booking] 
	ON booking.id_client = client.id_client 
INNER JOIN [room_in_booking] 
	ON room_in_booking.id_booking = booking.id_booking 
INNER JOIN [room] 
	ON room.id_room = room_in_booking.id_room
INNER JOIN [room_category]
	ON room_category.id_room_category = room.id_room_category
INNER JOIN [hotel]
	ON room.id_hotel = hotel.id_hotel  
	WHERE hotel.[name] = 'Космос'
		AND room_category.[name] = 'Бизнес'
		AND checkin_date = '2019-05-10'
UPDATE [room_in_booking]
SET room_in_booking.checkout_date = DATEADD(DAY, 2, checkout_date)
WHERE room_in_booking.id_room_in_booking IN
   (SELECT room_in_booking.id_room_in_booking FROM [room_in_booking]
	INNER JOIN [room] 
		ON room.id_room = room_in_booking.id_room
	INNER JOIN [room_category]
		ON room_category.id_room_category = room.id_room_category
	INNER JOIN [hotel]
		ON room.id_hotel = hotel.id_hotel  
		WHERE hotel.[name] = 'Космос'
			AND room_category.[name] = 'Бизнес'
			AND checkin_date = '2019-05-10')

/* 7. Найти все "пересекающиеся" варианты проживания. Правильное состояние: не
 может быть забронирован один номер на одну дату несколько раз, т.к. нельзя
 заселиться нескольким клиентам в один номер. Записи в таблице
 room_in_booking с id_room_in_booking = 5 и 2154 являются примером
 неправильного состояния, которые необходимо найти. Результирующий кортеж
 выборки должен содержать информацию о двух конфликтующих номерах.*/
SELECT t_1.id_room, t_1.id_room_in_booking, t_1.checkin_date, t_1.checkout_date, 
					t_2.id_room_in_booking, t_2.checkin_date, t_2.checkout_date FROM [room_in_booking] AS t_1
INNER JOIN [room_in_booking] AS t_2
	ON t_1.id_room = t_2.id_room AND t_1.id_room_in_booking != t_2.id_room_in_booking
	WHERE t_2.checkin_date >= t_1.checkin_date 
	    AND t_2.checkin_date < t_1.checkout_date

-- перепроверить обратную проверяемой ситуацию

-- 8. Создать бронирование в транзакции.
BEGIN DISTRIBUTED TRANSACTION;
	INSERT INTO booking (id_client, booking_date)
	VALUES (24057, '2022-04-06')	
COMMIT TRANSACTION
-- room_in_booking тоже нужно

--9. Добавить необходимые индексы для всех таблиц
CREATE INDEX IX_booking_id_client ON booking
(
	id_client 
);
CREATE INDEX IX_room_in_booking_id_booking ON room_in_booking
(
	id_booking 
);
CREATE INDEX IX_room_in_booking_id_room ON room_in_booking
(
	id_room 
);
CREATE INDEX IX_room_in_booking_checking_date ON room_in_booking
(
	checkin_date
);
CREATE INDEX IX_room_in_booking_checkout_date ON room_in_booking
(
	checkout_date
);
CREATE INDEX IX_room_id_hotel ON room
(
	id_hotel 
);
CREATE INDEX IX_room_id_room_category ON room
(
	id_room_category
);