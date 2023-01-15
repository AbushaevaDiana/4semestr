package ru.Shop.tests;
import org.openqa.selenium.chrome.ChromeDriver;
import org.testng.Assert;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Parameters;
import org.testng.annotations.Test;
import ru.Shop.metods.MainPage;

public class SearchTest {
    private ChromeDriver driver;
    private MainPage mainPage;
    @BeforeMethod
    public void setUp(){
        System.setProperty("webdriver.chrome.driver", "/home/diana/Documents/tests/chromedriver");
        driver = new ChromeDriver();
        driver.get("http://shop.qatl.ru/");
    }

    @Test(description = "Поиск товара")
    @Parameters({"inputWord", "outputWord"})
    public void testSearch(String inputWord, String outputWord){

        mainPage = new MainPage(driver);
        mainPage
                .searchEnterWord(inputWord)
                .clickSearch();

        String url = driver.getCurrentUrl();
        Assert.assertTrue(url.equals(outputWord), "Поиск не произошел");
    }
    @AfterMethod
    public void closeDriver() {
        System.out.println("test end");
        driver.close();
    }
}
