DROP TABLE Friend;
DROP TABLE FriendRequest;
DROP TABLE Achievement;
DROP TABLE AchievementType;
DROP TABLE Mail;
DROP TABLE MailType;
DROP TABLE User;
DROP TABLE Clan;

CREATE TABLE Clan (
 clanNo INT(1) AUTO_INCREMENT,
 PRIMARY KEY(clanNo)
);


CREATE TABLE User (
 userNo BIGINT(1) AUTO_INCREMENT,
 loginToken VARCHAR(36) UNIQUE NOT NULL,
 nickname VARCHAR(16) UNIQUE NOT NULL,
 level INT NOT NULL DEFAULT 1,
 exp INT NOT NULL DEFAULT 0,
 gold INT NOT NULL DEFAULT 0,
 jewel INT NOT NULL DEFAULT 0,
 coin INT NOT NULL DEFAULT 0,
 
 rubbiusCurrentStage VARCHAR(180) NOT NULL DEFAULT "0",
 elfCurrentStage VARCHAR(180) NOT NULL DEFAULT "0",
 personCurrentStage VARCHAR(180) NOT NULL DEFAULT "0",

 commonWin INT NOT NULL DEFAULT 0,
 commonDraw INT NOT NULL DEFAULT 0,
 commonLose INT NOT NULL DEFAULT 0,
 rubbiusWin INT NOT NULL DEFAULT 0,
 rubbiusDraw INT NOT NULL DEFAULT 0,
 rubbiusLose INT NOT NULL DEFAULT 0,
 personWin INT NOT NULL DEFAULT 0,
 personDraw INT NOT NULL DEFAULT 0,
 personLose INT NOT NULL DEFAULT 0,
 elfWin INT NOT NULL DEFAULT 0,
 elfDraw INT NOT NULL DEFAULT 0,
 elfLose INT NOT NULL DEFAULT 0,
 
 gradePoint INT NOT NULL DEFAULT 0,
 exist CHAR(1) NOT NULL DEFAULT '1',
 registerTime TIMESTAMP NOT NULL DEFAULT NOW(),
 lastLoginTime TIMESTAMP NOT NULL DEFAULT NOW(),
 lastLogoutTime TIMESTAMP NOT NULL DEFAULT NOW(),
 PRIMARY KEY(userNo),
 INDEX idx1(loginToken),
 INDEX idx2(nickname)
)DEFAULT CHARACTER SET utf8;

CREATE TABLE MailType (
 mailTypeNo INT(1) NOT NULL,
 title VARCHAR(50) NOT NULL,
 content VARCHAR(100) NOT NULL,
 rewardType INT(1) NOT NULL DEFAULT 0,
 rewardCount INT(1) NOT NULL DEFAULT 0,
 PRIMARY KEY(mailTypeNo)
);

CREATE TABLE Mail (
 mailNo BIGINT(1) AUTO_INCREMENT,
 userNo BIGINT(1) NOT NULL,
 mailTypeNo INT(1) NOT NULL,
 deleteTime TIMESTAMP NOT NULL DEFAULT NOW(),
 PRIMARY KEY(mailNo),
 FOREIGN KEY(userNo) REFERENCES User(userNo),
 INDEX idx1(userNo)
);

CREATE TABLE AchievementType (
 achievementTypeNo INT(1) NOT NULL,
 maxLevel INT(1) NOT NULL,
 PRIMARY KEY(achievementTypeNo)
);


CREATE TABLE Achievement (
 achievementNo BIGINT(1) AUTO_INCREMENT,
 userNo BIGINT(1) NOT NULL,
 achievementTypeNo INT(1) NOT NULL,
 level INT(1) NOT NULL DEFAULT 1,
 PRIMARY KEY(achievementNo),
 FOREIGN KEY(achievementTypeNo) REFERENCES AchievementType(achievementTypeNo),
 FOREIGN KEY(userNo) REFERENCES User(userNo),
 INDEX idx1(userNo)
);

CREATE TABLE FriendRequest (
 requestUserNo BIGINT(1) NOT NULL,
 receiveUserNo BIGINT(1) NOT NULL,
 FOREIGN KEY(requestUserNo) REFERENCES User(userNo),
 FOREIGN KEY(receiveUserNo) REFERENCES User(userNo),
 INDEX idx1(requestUserNo),
 INDEX idx2(receiveUserNo)
);

CREATE TABLE Friend (
 userNo1 BIGINT(1) NOT NULL,
 userNo2 BIGINT(1) NOT NULL,
 PRIMARY KEY(userNo1, userNo2),
 FOREIGN KEY(userNo1) REFERENCES User(userNo),
 FOREIGN KEY(userNo2) REFERENCES User(userNo),
 INDEX idx1(userNo1)
);

