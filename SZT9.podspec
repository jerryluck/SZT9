Pod::Spec.new do |s|
  s.name         = "SZT9"
  s.version      = "1.0.0"
  s.platform     = :ios, "8.0"
  s.summary      = "T9检索sdk"
  s.description  = "T9检索sdk,加入了包名检测"
  s.homepage     = "https://github.com/karlcool/SZT9"
  s.author       = { "yanzhi.liu" => "karlcool.l@qq.com" }
  s.source       = { :git => "https://github.com/karlcool/SZT9.git", :tag => "#{s.version}" }
  s.source_files        = 'T9Test/SZT9.framework/Headers/**/*.h'
  s.public_header_files = 'T9Test/SZT9.framework/Headers/**/*.h' 
  s.vendored_frameworks = 'T9Test/SZT9.framework'
  s.libraries = 'c++'
  
end