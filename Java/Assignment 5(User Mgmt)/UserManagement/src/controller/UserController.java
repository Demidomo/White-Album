package controller;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.LinkedList;
import java.util.List;

import dao.UserDAO;
import dto.User;

public class UserController implements UserDAO {
    // Here we will provide the implementation for the UserDAO interface

    private Connection connection;
    private PreparedStatement preparedStatement;
    private ResultSet resultSet;

    private static final String INSERT = "INSERT INTO user_table(name, email, password, age) VALUES(?, ?, ?, ?)";
    private static final String UPDATE = "UPDATE user_table SET name = ?, email = ?, password = ?, age = ? WHERE id = ?";
    private static final String DELETE = "DELETE FROM user_table WHERE id = ?";
    private static final String GETUSERLIST = "SELECT * FROM user_table";
    private static final String GETUSERBYID = "SELECT * FROM user_table WHERE id=?";
    private static final String GETUSERBYEMAILANDPASSWORD = "SELECT * FROM user_table WHERE email=? AND password=?";

    public UserController() {
        try {
            connection = DriverManager.getConnection(UserDAO.URL, UserDAO.USER, UserDAO.PASSWORD);
            System.out.println("Database connected");
        } catch (SQLException e) {
            System.out.println("Unable to Connect");
            e.printStackTrace();
        }
    }

    @Override
    public void insert(User user) {
        int rowAffected = 0;
        try {
            preparedStatement = connection.prepareStatement(INSERT);
            preparedStatement.setString(1, user.getName());
            preparedStatement.setString(2, user.getEmail());
            preparedStatement.setString(3, user.getPassword());
            preparedStatement.setInt(4, user.getAge());

            rowAffected = preparedStatement.executeUpdate(); // generally it returns the number of rows affected
        } catch (SQLException e) {
            System.out.println("Unable to insert Data");
            e.printStackTrace();
        } finally {
            try {
                preparedStatement.close();
            } catch (SQLException e) {
                System.out.println("Unable to close the statement");
                e.printStackTrace();
            }
        }

        if (rowAffected > 0) {
            System.out.println("INSERT WAS SUCESSFUL");
        }
    }

    @Override
    public void update(User user) {
        int rowAffected = 0;
        try {
            preparedStatement = connection.prepareStatement(UPDATE);
            preparedStatement.setString(1, user.getName());
            preparedStatement.setString(2, user.getEmail());
            preparedStatement.setString(3, user.getPassword());
            preparedStatement.setInt(4, user.getAge());

            preparedStatement.setInt(5, user.getId());

            rowAffected = preparedStatement.executeUpdate(); // generally it returns the number of rows affected
        } catch (SQLException e) {
            System.out.println("Unable to update Data");
            e.printStackTrace();
        } finally {
            try {
                preparedStatement.close();
            } catch (SQLException e) {
                System.out.println("Unable to close the statement");
                e.printStackTrace();
            }
        }

        if (rowAffected > 0) {
            System.out.println("UPDATE WAS SUCESSFUL");
        }
    }

    @Override
    public void delete(int id) {
        int rowAffected = 0;
        try {
            preparedStatement = connection.prepareStatement(DELETE);
            preparedStatement.setInt(1, id);

            rowAffected = preparedStatement.executeUpdate(); // generally it returns the number of rows affected
        } catch (SQLException e) {
            System.out.println("Unable to delete Data");
            e.printStackTrace();
        } finally {
            try {
                preparedStatement.close();
            } catch (SQLException e) {
                System.out.println("Unable to close the statement");
                e.printStackTrace();
            }
        }

        if (rowAffected > 0) {
            System.out.println("DELETE WAS SUCESSFUL");
        }
    }

    @Override
    public List<User> getUserList() {
        // Created the instance which we will return the user list in
        List<User> userList = new LinkedList<>();

        try {
            preparedStatement = connection.prepareStatement(GETUSERLIST);

            resultSet = preparedStatement.executeQuery(); // it returns the list of users

            while (resultSet.next()) {
                User user = new User();
                user.setId(resultSet.getInt("id"));
                user.setName(resultSet.getString("name"));
                user.setEmail(resultSet.getString("email"));
                user.setAge(resultSet.getInt("age"));
                user.setPassword(resultSet.getString("password"));
                userList.add(user);
            }

        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            try {
                preparedStatement.close();
            } catch (SQLException e) {
                System.out.println("Unable to close the statement");
                e.printStackTrace();
            }
        }

        return userList;
    }

    @Override
    public User getUserById(int id) {
    User user = null;
    PreparedStatement preparedStatement = null;
    ResultSet resultSet = null;
    
    try {
        preparedStatement = connection.prepareStatement(GETUSERBYID);
        preparedStatement.setInt(1, id);

        resultSet = preparedStatement.executeQuery();

        if (resultSet.next()) {
            user = new User();
            user.setId(resultSet.getInt("id"));
            user.setName(resultSet.getString("name"));
            user.setEmail(resultSet.getString("email"));
            user.setPassword(resultSet.getString("password"));
            user.setAge(resultSet.getInt("age"));
        }

    } catch (SQLException e) {
        e.printStackTrace();
        throw e;
    } finally {
        if (resultSet != null) {
            resultSet.close();
        }
        if (preparedStatement != null) {
            preparedStatement.close();
        }
    }

    return user;
}

    @Override
    public User getUserByEmailAndPassword(String email, String password) {
        User user = null;
        try {
            preparedStatement = connection.prepareStatement(GETUSERBYEMAILANDPASSWORD);
            preparedStatement.setString(1, email);
            preparedStatement.setString(2, password);

            resultSet = preparedStatement.executeQuery();

            if (resultSet.next()) {
                user = new User();
                user.setId(resultSet.getInt("id"));
                user.setName(resultSet.getString("name"));
                user.setEmail(resultSet.getString("email"));
                user.setPassword(resultSet.getString("password"));
                user.setAge(resultSet.getInt("age"));
            }

        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            try {
                preparedStatement.close();
            } catch (SQLException e) {
                System.out.println("Unable to close the statement");
                e.printStackTrace();
            }
        }

        return user;
    }

}