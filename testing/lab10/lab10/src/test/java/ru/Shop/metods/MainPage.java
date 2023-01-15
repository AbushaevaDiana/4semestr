package ru.Shop.metods;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;

public class MainPage {
    private WebDriver driver;
    private final String openSelectButtonXpath = "//*[@class='dropdown-toggle']";
    private final String startLoginationButtonXpath = "//a[text()='Вход']";
    private final String wordInputXpath = "//*[@id=\"typeahead\"]";
    private final String searchButtonXpath = "/html/body/div[3]/div/div/div[2]/div/form/input";
    private final String AddToCartButtonXpath = "//*[@id=\"productAdd\"]";

    public MainPage(WebDriver driver){
        this.driver = driver;
    }
    public MainPage openSelect() {
        WebElement loginButton = driver.findElement(By.xpath(openSelectButtonXpath));
        loginButton.click();
        return this;
    }
    public MainPage startLogination() {
        WebElement loginClic = driver.findElement(By.xpath(startLoginationButtonXpath));
        loginClic.click();
        return this;
    }
    public MainPage searchEnterWord(String word) {
        WebElement wordInput = driver.findElement(By.xpath(wordInputXpath));
        wordInput.sendKeys(word);
        return this;
    }

    public MainPage clickSearch() {
        WebElement button = driver.findElement(By.xpath(searchButtonXpath));
        button.click();
        return this;
    }

    public MainPage goToProductCard(String outputWord) {
        WebElement a = driver.findElement(By.xpath(outputWord));
        a.click();
        return this;
    }

    public  MainPage clickAddToCart() {
        WebElement button = driver.findElement(By.xpath(AddToCartButtonXpath));
        button.click();
        return this;
    }


}
