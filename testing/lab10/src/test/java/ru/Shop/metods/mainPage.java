package ru.Shop.metods;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;

public class mainPage {
    private WebDriver driver;

    public mainPage(WebDriver driver){
        this.driver = driver;
    }
    public mainPage openSelect() {
        WebElement loginButton = driver.findElement(By.xpath("/html/body/div[1]/div/div/div[1]/div/div[2]/a"));
        loginButton.click();
        return this;
    }
    public mainPage startLogination() {
        WebElement loginClic = driver.findElement(By.xpath("/html/body/div[1]/div/div/div[1]/div/div[2]/ul/li[1]/a"));
        loginClic.click();
        return this;
    }
    public mainPage searchEnterWord(String word) {
        WebElement loginInput = driver.findElement(By.xpath("//*[@id=\"typeahead\"]"));
        loginInput.sendKeys(word);
        return this;
    }

    public mainPage clickSearch() {
        WebElement button = driver.findElement(By.xpath("/html/body/div[3]/div/div/div[2]/div/form/input"));
        button.click();
        return this;
    }

    public mainPage goToProductCard(String inputWord) {
        WebElement a = driver.findElement(By.xpath("//a[text()='"+inputWord+"']"));
        a.click();
        return this;
    }

    public  mainPage clickAddToCart() {
        WebElement button = driver.findElement(By.xpath("//*[@id=\"productAdd\"]"));
        button.click();
        return this;
    }


}
