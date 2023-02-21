#include "usrdata.h"

// 添加用户
bool user_add(Hnode_t *manger, user *data)
{

    bool permissions = true;
    // 判断账号是否存在
    if (user_find(manger, data->phone))
    {
        permissions = false;
    }

    if (permissions)
    {
        // 不存在则添加并初始化数据
        char *name = (char *)malloc(70);
        strcat(name, "新用户");
        strcat(name, data->phone);
        data->name = name;
        data->money = 0.0;
        user_TailInsert(manger, data);
        return true;
    }
    else
    {
        printf("该账号已存在！\n");
        return false;
    }
}
// 注册
user* logon(Hnode_t *manger)
{   
    char *phone = (char *)malloc(100);
    char *passwad = (char *)malloc(100);
    //shuru

    //判断账号密码格式
    if (strlen(phone) != 11)
    {
        printf("phone number is false\n");
        free(phone);
        free(passwad);
        return NULL;
    }
    if (strlen(passwad) > 12)
    {
        printf("passwad longer\n");
        free(phone);
        free(passwad);
        return NULL;
    }
    
    //创建新的堆内存
    user *new = (user *)malloc(sizeof(user));
    char *new_phone = (char *)malloc(12);
    char *new_passwad = (char *)malloc(13);
    strcpy(new_phone, phone);
    strcpy(new_passwad, passwad);
    new->phone = new_phone;
    new->passwd = new_passwad;
    //释放输入缓冲区
    free(phone);
    free(passwad);

    //开始添加用户
    if (!user_add(manger,new))
    {
        printf("logon fail!\n");
        new->phone = NULL;
        new->passwd = NULL;
        free(new);
        free(phone);
        free(passwad);
        return NULL;
    }
    printf("logon success!\n");
    return new;
}
// 登录
user *login(Hnode_t *manger)
{
    char *ph = (char *)malloc(100);
    char *pswd = (char *)malloc(100);

    // 判断账号密码格式
    if (strlen(ph) != 11)
    {
        printf("phone number is false\n");
        free(ph);
        free(pswd);
        return NULL;
    }
    if (strlen(pswd) > 12)
    {
        printf("passwad longer\n");
        free(ph);
        free(pswd);
        return NULL;
    }

    //开始登录
    user *t_user = user_find_get(manger, ph);
    if (t_user == NULL)
    {
        printf("USER IS NOT exist\n");
        free(ph);
        free(pswd);
        return NULL;
    }
    if (strcmp(t_user->passwd, pswd) == 0)
    {
        printf("PASSWAD IS NOT ture\n");
        free(ph);
        free(pswd);
        return NULL;
    }
    return t_user;
}




