package ru.Shop.tests;
import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Parameters;
import org.testng.annotations.Test;
import ru.Shop.metods.mainPage;

import java.util.concurrent.TimeUnit;

public class searchTest {
    private ChromeDriver driver;
    private mainPage mainPage;
    @BeforeMethod
    public void setUp(){
        System.setProperty("webdriver.chrome.driver", "/home/diana/Documents/tests/chromedriver");
        driver = new ChromeDriver();
        driver.get("http://shop.qatl.ru/");
    }

    @Test(description = "Поиск товара")
    @Parameters({"inputWord", "outputWord"})
    public void testSearch(String inputWord, String outputWord){

        mainPage = new mainPage(driver);
        mainPage
                .searchEnterWord(inputWord)
                .clickSearch();

        String url = driver.getCurrentUrl();
        if(url.equals(outputWord)) {
            System.out.println("Успешный поиск");
        }
        else {
            System.out.println("Тест не пройден");
        }
    }
    @AfterMethod
    public void closeDriver() {
        System.out.println("test end");
        driver.close();
    }
}
