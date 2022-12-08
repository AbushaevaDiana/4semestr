package ru.Shop.tests;

import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Parameters;
import org.testng.annotations.Test;
import ru.Shop.metods.cart;

import java.util.concurrent.TimeUnit;

public class buyTest {
    private ChromeDriver driver;
    private ru.Shop.metods.mainPage mainPage;
    private ru.Shop.metods.cart cart;
    private ru.Shop.metods.login login;
    @BeforeMethod
    public void setUp(){
        System.setProperty("webdriver.chrome.driver", "/home/diana/Documents/tests/chromedriver");
        driver = new ChromeDriver();
        driver.get("http://shop.qatl.ru/");
    }

    @Test(description = "Добавление товара в корзину и оформление заказа")
    @Parameters({"inputWord", "inputLogin", "password"})
    public void testAdding(String inputWord, String inputLogin, String password){
        mainPage = new ru.Shop.metods.mainPage(driver);
        mainPage
                .openSelect()
                .startLogination();
        login = new ru.Shop.metods.login(driver);
        login
                .setLogin(inputLogin)
                .setPassword(password)
                .clickEnter()
                .goToMainPage();
        mainPage = new ru.Shop.metods.mainPage(driver);
        mainPage
                .goToProductCard(inputWord)
                .clickAddToCart();
        driver.manage().timeouts().implicitlyWait(5, TimeUnit.SECONDS);
        cart = new ru.Shop.metods.cart(driver);
        cart
                .clickBuyInModalWindow()
                .clickBuy();
    }

    public void check(String inputWord) {
        WebElement alert = driver.findElement(By.xpath("//*[@class='alert alert-success'][text()='Спасибо за Ваш заказ. " +
                "В ближайшее время с Вами свяжется менеджер для согласования заказа']"));
        if(alert.isDisplayed()) {
            System.out.println("Успешно оформлен заказ");
        }
    }
    @AfterMethod
    public void closeDriver() {
        System.out.println("test end");
        driver.close();
    }
}
